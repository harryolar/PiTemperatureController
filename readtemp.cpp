#include "readtemp.h"
#include <QProcess>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


//******************************************************************************
ReadTemp::ReadTemp(QObject *parent) :
    QObject(parent)
//******************************************************************************
{


    //initI2C();

    sampleTimer.setSingleShot(false);
    connect(&sampleTimer, SIGNAL(timeout()), this, SLOT(sampleTimerEvent()));

    counter =0;
}

//******************************************************************************
void ReadTemp::ReadStart(int msecPerioud)
//******************************************************************************
{
    sampleTimer.start(msecPerioud);
}

//******************************************************************************
void ReadTemp::ReadStop()
//******************************************************************************
{
    sampleTimer.stop();
}

//******************************************************************************
void ReadTemp::sampleTimerEvent()
//******************************************************************************
{
    bool test;
    float value=0;

    test =readExternalTemperature(value);
    if(test == false)
    {
        printf("value not read\n");
    }
    else
    {
       qDebug()<<"Return value"<< value <<endl;
    }


     emit ReadDataReady(value , true);

}





//******************************************************************************
bool ReadTemp::readExternalTemperature(float &value)
//******************************************************************************
{
         bool test;
         float floatValue;
         QProcess readTempProcess;

         readTempProcess.start("./readTempOnce", QStringList() << "");
         if (!readTempProcess.waitForStarted())
             return false;


         if (!readTempProcess.waitForFinished())
             return false;

         //QByteArray result = readTempProcess.readAllStandardOutput();
         QByteArray result = readTempProcess.readAll();
         QString command(result); //to convert byte array to string

         //qDebug()<<"Return value"<< command <<endl;
         floatValue=command.toFloat(&test);
         if(test ==false)
         {
             return false;
         }
         value=floatValue;

         return true;

}
