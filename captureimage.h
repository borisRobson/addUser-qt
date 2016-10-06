#ifndef CAPTUREIMAGE_H
#define CAPTUREIMAGE_H

#include "opencv2/opencv.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <QtCore>
#include <QTimer>

using namespace cv;
using namespace std;


class captureimage : public QObject
{
    Q_OBJECT
public:
    captureimage();
    void writeImage(Mat &image, string name);
public slots:
    void imageSent(int exitCode, QProcess::ExitStatus exitStatus);
signals:
    void imageSent(QString text);
};

#endif // CAPTUREIMAGE_H
