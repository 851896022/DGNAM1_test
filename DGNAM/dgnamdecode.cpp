#include "dgnamdecode.h"

DGNAMDecode::DGNAMDecode(QObject *parent) : QObject(parent)
{

}
void DGNAMDecode::initThis(int port)
{
    udp=new QUdpSocket;

    connect(udp,SIGNAL(readyRead()),this,SLOT(onReceived()));
    udp->bind(port);


    player[0]=new QMediaPlayer;
    player[1]=new QMediaPlayer;
    dataCache[0]=new QByteArray;
    ds[0]=new QDataStream(dataCache[0],QIODevice::ReadWrite);


    player[0]->setMedia(QMediaContent(),ds[0]->device());
    disConnectCount= new QTimer;
    connect(disConnectCount,SIGNAL(timeout()),this,SLOT(onDisCon()));
    disConnectCount->start(100);



}
void DGNAMDecode::onDisCon()
{
    countMp3++;
    countTfu++;
    if(countMp3==50)
    {
        g->isWorking=false;
        qDebug()<<"调幅度数据丢失";
    }
    if(countTfu==50)
    {
        g->isWorking=false;
        qDebug()<<"音频数据丢失";
    }
}
void DGNAMDecode::onReceived()
{
    while(udp->bytesAvailable())
    {
        unsigned char ch[65536];
        int size;
        size=udp->readDatagram((char*)ch,65536);
        if(size>0)
        {
            if(size == 32)
            {
                if(ch[0]== 255 && ch[1] == 0)
                {
                    g->fre[0]=ch[6]*256*256*256+ch[7]*256*256+ch[4]*256+ch[5];
                    g->pow[0]=ch[8]*256+ch[9];
                    g->tfu[0]=ch[11];
                    g->fre[1]=ch[6+8]*256*256*256+ch[7+8]*256*256+ch[4+8]*256+ch[5+8];
                    g->pow[1]=ch[8+8]*256+ch[9+8];
                    g->tfu[1]=ch[11+8];
                    if(countTfu>=50)
                    {
                        qDebug()<<"调幅度数据恢复";
                        countTfu=0;
                    }
                    else
                    {
                        countTfu=0;
                    }
                }
                else
                {
                    qDebug()<<"参数数据错误："<<QByteArray((char*)ch,size).toHex();
                }

            }
            else if(size == 392)
            {

                if(ch[0]==0xfb && ch[1]==0x02)
                {
                    if(countMp3>=50)
                    {
                        qDebug()<<"音频数据恢复";
                        countMp3=0;
                    }
                    else
                    {
                        countMp3=0;
                    }
                }
                else
                {
                    qDebug()<<"音频数据错误："<<QByteArray((char*)ch,size).toHex();
                }
            }
            else
            {
                qDebug()<<"数据长度异常："<<size;
            }

        }
    }
}
