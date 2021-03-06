#ifndef STREAM_H
#define STREAM_H

#include <QObject>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QFile>
#include <vector>
#include <string>

#include "gst/gst.h"
#include "gst/app/gstappsink.h"
#include "glib-2.0/glib.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "mainwindow.h"

#include <QApplication>
#include <QTimer>
#include <QWidget>
#include <glib.h>
#include <gst/interfaces/xoverlay.h>

using namespace std;
using namespace cv;

class stream : public QObject
{
    Q_OBJECT
public:
    stream();
    bool buildpipeline(MainWindow &window);
    void startstream();
public slots:
    void printtext();
    void capTimeOut();
    void updateWindow();
};

#endif // STREAM_H
