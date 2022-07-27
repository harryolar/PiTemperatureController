#include "pidcontroller.h"
#include <stdio.h>
#include <stdlib.h>
#include <QDebug>
#include "relays.h"


//******************************************************************************
PIDController::PIDController(QObject *parent) :
    QObject(parent)
//******************************************************************************
{
    kP =1.0f;
    kI =1.0f;
    kD =1.0f;
    Integral=0.0f;

    relays=new Relays();

}

//******************************************************************************
void PIDController::PIDInit(float P_Param, float I_Param, float D_Param, float IntegralTreshold_Param , float DriveThreshold_Param)
//******************************************************************************
{
    kP = P_Param;
    kI = I_Param ;
    kD = D_Param;
    errorTemperature = 0.0f;

    Integral=0.0f;
    IntegralThreshold = IntegralTreshold_Param;
    DriveThreshold = DriveThreshold_Param ;

}//end func



//******************************************************************************
void PIDController::PIDTask(float tempValue,bool status)
//******************************************************************************
{
    //http://www.maelabs.ucsd.edu/mae156alib/control/PID-Control-Ardunio.pdf

    errorTemperature =   setTemperature- tempValue;

    if (errorTemperature < IntegralThreshold)
    { // prevent integral 'windup'
       Integral = Integral + errorTemperature; // accumulate the error integral
    }
    else
    {
       Integral = 0; // zero it if out of bounds
    }

    P =errorTemperature * kP;
    I =Integral * kI;
    D = (lastTemperature -tempValue) *kD ;

    //output = Kp * err + (Ki * int * dt) + (Kd * der /dt);
    drive = P +I +D ;

    qDebug() << "PID loop P=" <<P <<" I=" <<I << " D=" <<D << "Drive = "<< drive<<" Set Temperature="<<setTemperature << " Temperature="<<tempValue <<"DriveThreshold"<<DriveThreshold<<endl;


    if(drive <  (0-DriveThreshold)) //
    {
          qDebug()<<"Cooling"<<endl;
          relays->RelaysSetOn(Relays::RELAY_COLD);
          relays->RelaysSetOff(Relays::RELAY_HOT);
    }
    else if (drive >= 0)
    {
        qDebug()<<"Heating="<<endl;
         relays->RelaysSetOn(Relays::RELAY_HOT);
         relays->RelaysSetOff(Relays::RELAY_COLD);
    }
    else
    {
        qDebug()<<"Hold"<<endl;
        relays->RelaysSetOff(Relays::RELAY_HOT);
        relays->RelaysSetOff(Relays::RELAY_COLD);
    }

    lastTemperature =tempValue;
}

