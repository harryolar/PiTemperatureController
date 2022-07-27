#ifndef READTEMP_H
#define READTEMP_H

#include <QObject>
#include <QTimer>


class ReadTemp : public QObject
{
    Q_OBJECT
public:
    explicit ReadTemp(QObject *parent = 0);
    
signals:
    void ReadDataReady(float value , bool error);
public slots:
     void ReadStart(int msecPerioud);
     void ReadStop();

private slots:

    void sampleTimerEvent();

private:
     QTimer sampleTimer;

     float counter;
     bool readExternalTemperature(float & value);
};



#endif // READTEMP_H
