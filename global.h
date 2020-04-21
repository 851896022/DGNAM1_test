#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <QString>
#include <QDir>
#include <QFile>
#include <QTimer>
#include <QDebug>

class GLobal : public QObject
{
    Q_OBJECT
public:
    explicit GLobal(QObject *parent = nullptr);
    ~GLobal();
    int fre[2];
    int pow[2];
    int tfu[2];
    bool isWorking = true;
signals:

public slots:
};
extern GLobal *g;
#endif // GLOBAL_H
