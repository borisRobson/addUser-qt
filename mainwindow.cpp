#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "captureimage.h"
#include "stream.h"

captureimage *capimg;
stream *stm;

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    button = ui->pushButton;
    txtId = ui->textEdit;
    txtLog = ui->textEdit_2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateText(QString text)
{
    QString log = QString("Sent file: ") + text;
    ui->textEdit_2->append(log);
}


