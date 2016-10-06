#include "captureimage.h"
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>

int filecount;
string file;
captureimage::captureimage()
{
    filecount = 0;
}


void captureimage::writeImage(Mat &image, string name)
{

    if(filecount == 3){
        filecount = 0;
    }
    //set image write params
    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
    compression_params.push_back(50);

    string num = static_cast<ostringstream*>( &(ostringstream() << filecount) )->str();

    file = name + "_" + num + ".jpg";
    string location = "./captures/" + file;
    imwrite(location, image, compression_params);

    cout << file << endl;

    //busybox to panel
    QProcess *sendImage = new QProcess(0);
    connect(sendImage, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(imageSent(int,QProcess::ExitStatus)));
    string cmd = "busybox tftp -p -l " + location + " -r " + file + " fe80::20b:d6ff:fe3e:55f9%eth0";
    const char *charCmd = cmd.c_str();
    QString sendImageCmd = QString(charCmd);
    sendImage->start(sendImageCmd);


    filecount++;
}

void captureimage::imageSent(int exitCode, QProcess::ExitStatus exitStatus)
{
    Q_UNUSED(exitStatus);
    QString text = QString::fromStdString(file);
    if(exitCode == 0){
        qDebug() << "image sent";
        emit imageSent(text);
    }else{
        qDebug () << "Error sending file";
        qDebug () << "Check path and destination";
    }
}
