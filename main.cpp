#include "mainwindow.h"
#include <QApplication>
#include "global.h"
#include "DGNAM/dgnamdecode.h"
#include "qlog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMessageHandler(QLog::messageHandler);
    g=new GLobal;

    DGNAMDecode d;
    d.initThis(2000);

    MainWindow w;
    w.show();

    return a.exec();
}
