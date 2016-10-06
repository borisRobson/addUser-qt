#include "stream.h"

GstElement *asink;
GstElement *pipeline;
GstPad *tee_video2_pad, *tee_video_pad;
GstPad *queue_video_pad, *queue_video2_pad;
GstPadTemplate *tee_src_pad_template;

stream::stream()
{
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
    GstElement *q2 = gst_element_factory_make("queue", NULL);
    GstElement *imgsink = gst_element_factory_make ("xvimagesink", NULL);
    asink = gst_element_factory_make("appsink", NULL);

    gst_util_set_object_arg(G_OBJECT(caps), "caps",
                            "video/x-raw-yuv, width=640, height=480");

    gst_bin_add_many (GST_BIN (pipeline), src,scale, caps, conv,tee,q1,asink,q2,  imgsink, NULL);

    if(!gst_element_link_many (src,scale, caps, conv,  tee, NULL))
        return false;

    gst_element_link_many(q1,asink, NULL);
    gst_element_link_many(q2,imgsink, NULL);

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

    //get window ID and assign viewing area
    //overlay ximagesink to this area
    WId xwinid = window.winId();
    gst_x_overlay_set_window_handle (GST_X_OVERLAY (imgsink), xwinid);
    gst_x_overlay_set_render_rectangle(GST_X_OVERLAY(imgsink),5,5,640,480);
    gst_x_overlay_expose(GST_X_OVERLAY(imgsink));

    return true;
}

void stream::startstream()
{
    // run the pipeline
    GstStateChangeReturn sret = gst_element_set_state (pipeline,
        GST_STATE_PLAYING);
    if (sret == GST_STATE_CHANGE_FAILURE) {
      gst_element_set_state (pipeline, GST_STATE_NULL);
      gst_object_unref (pipeline);
      // Exit application
      QTimer::singleShot(0, QApplication::activeWindow(), SLOT(quit()));
    }
}

