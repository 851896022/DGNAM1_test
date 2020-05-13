#include "mainwindow.h"
#include <QApplication>
#include "global.h"
#include "DGNAM/dgnamdecode.h"
#include "qlog.h"
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMessageHandler(QLog::messageHandler);
    g=new GLobal;

    DGNAMDecode d;
    d.initThis(2000);

    MainWindow w;

    QObject::connect(&w,SIGNAL(changePort(int)),&d,SLOT(reInitThis(int)));
    QObject::connect(&w,SIGNAL(reSet()),&d,SLOT(alarmReset()));

    w.show();

    return a.exec();
}
