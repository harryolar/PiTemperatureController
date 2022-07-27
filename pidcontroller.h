#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include <QObject>
#include <QTimer>
#include "relays.h"

class PIDController : public QObject
{
    Q_OBJECT
public:
    explicit PIDController(QObject *parent = 0);
    
signals:
    

private slots:



private:


    float P;
    float I;
    float D;

    float kP;
    float kI;
    float kD;

    float Integral;
    float IntegralThreshold;
    float DriveThreshold;

    float drive;

    float errorTemperature;

    float setTemperature;
    float lastTemperature;

    Relays * relays;

public slots:

    void PIDInit(float P_Param , float I_Param , float D_Param , float IntegralTreshold_Param , float DriveThreshold_Param);


    void PIDTask(float tempValue,bool status);
    void setSetTemperature(float temperature){ setTemperature =temperature;}




};

#endif // PIDCONTROLLER_H
