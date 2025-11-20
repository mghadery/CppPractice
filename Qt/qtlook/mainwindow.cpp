#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDateTime>
#include <QTimer>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    darkmode = false;
    refresh_mode();

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

void MainWindow::on_uimodeBut_clicked()
{
    darkmode = !darkmode;
    refresh_mode();
}

void MainWindow::refresh_mode()
{
    if (darkmode)
    {
        ui->uimodeBut->setProperty("lightmode", false);
        ui->uimodeBut->setProperty("darkmode", true);
    }
    else
    {
        ui->uimodeBut->setProperty("lightmode", true);
        ui->uimodeBut->setProperty("darkmode", false);
    }
    ui->uimodeBut->style()->unpolish( ui->uimodeBut);
    ui->uimodeBut->style()->polish( ui->uimodeBut);
    //ui->centralwidget->update();
}

