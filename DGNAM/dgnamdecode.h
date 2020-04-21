#ifndef DGNAMDECODE_H
#define DGNAMDECODE_H

#include <QObject>
#include <QUdpSocket>
#include "global.h"
#include <QMediaPlayer>
#include <QDataStream>
class DGNAMDecode : public QObject
{
    Q_OBJECT
public:
    explicit DGNAMDecode(QObject *parent = nullptr);
    QUdpSocket *udp;
    QTimer *disConnectCount;
    QMediaPlayer* player[2];
    QDataStream* ds[2];
    QByteArray* dataCache[2];
    int countTfu=0;
    int countMp3=0;
signals:

public slots:
    void onReceived();
    void initThis(int);
    void onDisCon();
};

#endif // DGNAMDECODE_H
