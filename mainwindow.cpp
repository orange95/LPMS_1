#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include "LpmsSensorI.h"
#include "LpmsSensorManagerI.h"
#include "stdio.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"hi";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_check_connect_clicked()
{
    int i=1;
    ImuData test;
    // Gets a LpmsSensorManager instance
    LpmsSensorManagerI* manager = LpmsSensorManagerFactory();
    // Connects to LPMS-B sensor with address 00:11:22:33:44:55
    LpmsSensorI* lpms = manager->addSensor(DEVICE_LPMS_B, "00:06:66:A0:BB:4A");
    while(1){
        // Checks, if conncted
        if (lpms->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED) {
            qDebug()<<"connected:"<<i;
            break;
        }
    }
    for(i=1;i<100;i=i+1)
    {

    // Reads quaternion data
    test = lpms->getCurrentData();
    float x=test.a[0];
    float y=test.a[1];
    float z=test.a[2];
    // Shows data
//    qDebug()<<"Timestamp="<<d.timeStamp<<" qW="<<d.q[0]<<" qX="<<d.q[1]<<" qY="<<d.q[2]<<" qZ="<<d.q[3];
//            printf("Timestamp=%f, qW=%f, qX=%f, qY=%f, qZ=%f¥n", d.timeStamp, d.q[0], d.q[1], d.q[2], d.q[3]);

//    test = lpms->getCalibratedSensorData(float g[3],float a[3], float b[3]);
    ui->lcdNumber_X->display(x);
    ui->lcdNumber_Y->display(y);
    ui->lcdNumber_Z->display(z);
    Sleep(50);

    qDebug()<<"Acceleration: x="<<x<<" y="<<y<<" z="<<z;



    }
    // Removes the initialized sensor
    //manager->removeSensor(lpms);
    // Deletes LpmsSensorManager object
    //delete manager;
    qDebug()<<"leave check_connect";
}
