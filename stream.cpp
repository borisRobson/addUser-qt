#include "stream.h"
#include "captureimage.h"

GstElement *asink, *imgsink;
GstElement *pipeline;
GstPad *tee_video2_pad, *tee_video_pad;
GstPad *queue_video_pad, *queue_video2_pad;
GstPadTemplate *tee_src_pad_template;

gboolean bus_cb(GstBus *bus, GstMessage *msg, gpointer user_data);
GstFlowReturn new_preroll(GstAppSink* asink, gpointer data);
GstFlowReturn new_buffer(GstAppSink* asink, gpointer data);

MainWindow *win;


QTimer *captureTimer;
int captureCount;


captureimage *imgcap;

stream::stream()
{
    imgcap = new captureimage();
    captureCount = 0;
    captureTimer = new QTimer();
    captureTimer->setInterval(250);
    connect(captureTimer, SIGNAL(timeout()), SLOT(capTimeOut()));
}


bool stream::buildpipeline(MainWindow &window)
{
    pipeline = gst_pipeline_new ("xvoverlay");
    GstElement *src = gst_element_factory_make ("v4l2src", NULL);
    GstElement *scale = gst_element_factory_make("videoscale", NULL);
    GstElement *caps = gst_element_factory_make("capsfilter", NULL);
    GstElement *conv = gst_element_factory_make("ffmpegcolorspace", NULL);
    GstElement *tee  = gst_element_factory_make("tee", NULL);
    GstElement *q1 = gst_element_factory_make("queue", NULL);
    imgsink = gst_element_factory_make ("xvimagesink", NULL);
    GstElement *q2 = gst_element_factory_make("queue", NULL);
    GstElement *rgbfilter = gst_element_factory_make("capsfilter", NULL);
    GstElement *conv2 = gst_element_factory_make("ffmpegcolorspace", NULL);

    asink = gst_element_factory_make("appsink", NULL);
    //set app sink properties
    gst_app_sink_set_emit_signals((GstAppSink*)asink, true);
    gst_app_sink_set_drop((GstAppSink*)asink, true);
    gst_app_sink_set_max_buffers((GstAppSink*)asink, 10);
    GstAppSinkCallbacks callbacks = {NULL, new_preroll, new_buffer, NULL};
    gst_app_sink_set_callbacks(GST_APP_SINK(asink), &callbacks, NULL, NULL);


    gst_util_set_object_arg(G_OBJECT(caps), "caps",
                            "video/x-raw-yuv, width=640, height=480");
    gst_util_set_object_arg(G_OBJECT(rgbfilter), "caps",
                            "video/x-raw-gray, width=640, height=480, bpp=8, depth=8");

    gst_bin_add_many (GST_BIN (pipeline), src,scale, caps, conv,rgbfilter,conv2,tee,q1, asink,q2,  imgsink, NULL);

    if(!gst_element_link_many (src,scale, caps, conv, rgbfilter, conv2, tee, NULL))
        return false;

    if(!gst_element_link_many(q1, asink, NULL)){
        qDebug() << "could not link filter";
        return false;
    }

    if(!gst_element_link_many(q2,imgsink, NULL))
        return false;

    //negotiate tee -> queue pads and link
    //get tee src pads
    tee_src_pad_template = gst_element_class_get_pad_template (GST_ELEMENT_GET_CLASS (tee), "src%d");
    tee_video_pad = gst_element_request_pad(tee, tee_src_pad_template, NULL, NULL);
    tee_video2_pad = gst_element_request_pad(tee, tee_src_pad_template, NULL, NULL);
    g_print("Recieved tee pads: '%s' and '%s'\n", gst_pad_get_name(tee_video_pad), gst_pad_get_name(tee_video2_pad));

    //get queue pads
    queue_video_pad = gst_element_get_static_pad(q1, "sink");
    queue_video2_pad = gst_element_get_static_pad(q2, "sink");
    g_print("recieved queue pads: '%s' , and '%s'\n", gst_pad_get_name(queue_video_pad), gst_pad_get_name(queue_video2_pad));

    //link
    if(gst_pad_link(tee_video_pad, queue_video_pad) != GST_PAD_LINK_OK ||
        gst_pad_link(tee_video2_pad, queue_video2_pad) != GST_PAD_LINK_OK){
        g_printerr("could not link tee \n");
        return false;
    }

    GstBus *bus = GST_ELEMENT_BUS(pipeline);
    gst_bus_add_watch(bus, bus_cb, NULL);
    gst_object_unref(bus);


    /*
     * assing window pointer to heap
     * can be used in this scope
     */

    win = &window;

    //get window ID and assign viewing area
    //overlay ximagesink to this area
    WId xwinid = win->winId();
    gst_x_overlay_set_window_handle (GST_X_OVERLAY (imgsink), xwinid);
    gst_x_overlay_set_render_rectangle(GST_X_OVERLAY(imgsink),5,5,640,480);
    gst_x_overlay_expose(GST_X_OVERLAY(imgsink));

    connect(win->button, SIGNAL(clicked()), this, SLOT(printtext()));
    connect(imgcap, SIGNAL(imageSent(QString)), win, SLOT(updateText(QString)));

    gst_element_set_state(pipeline, GST_STATE_PAUSED);

    return true;
}

void stream::startstream()
{
    // run the pipeline
    GstStateChangeReturn sret = gst_element_set_state (pipeline,GST_STATE_PLAYING);
    if (sret == GST_STATE_CHANGE_FAILURE) {
      gst_element_set_state (pipeline, GST_STATE_NULL);
    }
}

gboolean bus_cb(GstBus *bus, GstMessage *msg, gpointer user_data)
{
    Q_UNUSED(bus);
    Q_UNUSED(user_data);
    //parse bus messages
    switch(GST_MESSAGE_TYPE(msg)){
        case GST_MESSAGE_ERROR:{
            //quit on error
            GError *err;
            gchar *dbg;
            gst_message_parse_error(msg, &err, &dbg);
            gst_object_default_error(msg->src, err, dbg);
            g_clear_error(&err);
            g_free(dbg);
            gst_object_unref (pipeline);
            // Exit application
            QTimer::singleShot(0, QApplication::activeWindow(), SLOT(quit()));
            break;
        }
        case GST_MESSAGE_STATE_CHANGED:{
            GstState old_state, new_state, pending_state;
            gst_message_parse_state_changed(msg, &old_state, &new_state, &pending_state);
            //just show pipeline messages
            if(GST_OBJECT_NAME(msg->src) == GST_OBJECT_NAME(pipeline)){
                g_print("'%s' state changed from %s to %s \n", GST_OBJECT_NAME(msg->src), gst_element_state_get_name(old_state), gst_element_state_get_name(new_state));
            }
            break;
        }
        default:
            break;
    }
    return TRUE;

}

GstFlowReturn new_preroll(GstAppSink* asink, gpointer data)
{
    Q_UNUSED(asink);
    Q_UNUSED(data);
    qDebug() << "new preroll";
    return GST_FLOW_OK;

}

GstFlowReturn new_buffer(GstAppSink* asink, gpointer data)
{
    Q_UNUSED(asink);
    Q_UNUSED(data);
    gst_x_overlay_expose(GST_X_OVERLAY(imgsink));

    return GST_FLOW_OK;
}


void stream::printtext()
{
    captureTimer->start();
}

void stream::capTimeOut()
{
    captureCount++;
    if(captureCount > 3){
        captureTimer->stop();
        captureCount = 0;
        return;
    }

    QString str = win->txtId->toPlainText();

    GstBuffer *buff = gst_app_sink_pull_buffer((GstAppSink*)asink);
    Mat frame(Size(640,480), CV_8UC1, GST_BUFFER_DATA(buff), Mat::AUTO_STEP);
    string user = "user" + str.toStdString();
    imgcap->writeImage(frame, user);
}

void stream::updateWindow()
{
    qDebug() <<__FUNCTION__;
    QString info = QString("Image: ") + QString(captureCount) + QString(" sent");

}
