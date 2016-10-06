#include <glib.h>
#include <gst/gst.h>
#include <gst/interfaces/xoverlay.h>
#include <gst/app/gstappsink.h>

#include <QApplication>
#include <QTimer>
#include <QWidget>

#include "mainwindow.h"
#include "captureimage.h"
#include "stream.h"

stream *strm;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (!g_thread_supported ())
      g_thread_init (NULL);

    if(!gst_is_initialized())
        gst_init(&argc, &argv);

    strm = new stream();
    MainWindow window;

    if(!strm->buildpipeline(window)){
        qDebug() << "Could not build pipeline, exiting...";
        return -1;
    }

    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit ()));

    window.show();

    strm->startstream();

    int ret = app.exec();

    window.hide();

    return ret;
}
