#include <glib.h>
#include <gst/gst.h>
#include <gst/interfaces/xoverlay.h>
#include <gst/app/gstappsink.h>

#include "captureimage.h"

captureimage::captureimage()
{
}


void captureimage::writeImage(Mat &image, string name)
{
    /*
    //set image write params
    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);

    //set filename and write image
    //string filename = "./faces/" +name + ".png";
    //imwrite(filename,image,compression_params);

    //busybox to panel
    QProcess *sendImage = new QProcess(0);
    connect(sendImage, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(imageSent(int,QProcess::ExitStatus)));
    string cmd = "busybox tftp -p -l " + filename + " -r " + name + ".png fe80::20b:d6ff:fe3e:55f9%eth0";
    const char *charCmd = cmd.c_str();
    QString sendImageCmd = QString(charCmd);
    sendImage->start(sendImageCmd);
        */
}

void captureimage::imageSent(int exitCode, QProcess::ExitStatus exitStatus)
{
    /*
    Q_UNUSED(exitCode);
    Q_UNUSED(exitStatus);
    qDebug() << "image sent";
    */
}
