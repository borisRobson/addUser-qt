#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <iostream>
#include <QDebug>

#include <QPushButton>
#include <QTextEdit>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPushButton *button;
    QTextEdit *txtId;
    QTextEdit *txtLog;


public slots:
    void updateText(QString text);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
