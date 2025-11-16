#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDateTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDateTime now = QDateTime::currentDateTime();
    QString nowStr = now.toString("yyyy-MM-dd HH:mm:ss");
    ui->currentTime->setText(nowStr);

    QTimer *timer = new QTimer(this); //when this is destroyed, timer is destructed automatically

    connect(timer, &QTimer::timeout, [=](){
        QDateTime now = QDateTime::currentDateTime();
        ui->currentTime->setText((now.toString("yyyy-MM-dd HH:mm:ss")));
    });
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
