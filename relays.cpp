#include "relays.h"
#include <QDebug>
#include <QProcess>

//******************************************************************************
Relays::Relays(QObject *parent) :
    QObject(parent)
  //******************************************************************************
{

}


//******************************************************************************
void Relays::RelaysSetOn(Relays::RELAYS_STATE state)
//******************************************************************************
{
    QString arguments="";
    switch(state)
    {
        case RELAY_HOT:
             qDebug() <<"RELAY_HOT on"<<endl;
             arguments="HOT";
             break;
        case RELAY_COLD:
             qDebug() <<"RELAY_COLD on"<<endl;
             arguments="COLD";
             break;
        case RELAYS_COLD_AND_HOT:
             qDebug() <<"RELAYS_COLD_AND_HOT on"<<endl;
             arguments="COLD_AND_HOT";
             break;
        default:
             arguments="";
             break;
    }

    QProcess relayProcess;

    relayProcess.start("./relaysOn", QStringList() << arguments);
    if (!relayProcess.waitForStarted())
        return ;


    if (!relayProcess.waitForFinished())
        return ;

}//end func


//******************************************************************************
void Relays::RelaysSetOff(Relays::RELAYS_STATE state)
//******************************************************************************
{
    QString arguments="";

    switch(state)
    {
        case RELAY_HOT:
             qDebug() <<"RELAY_HOT off"<<endl;
             arguments="HOT";
             break;
        case RELAY_COLD:
             qDebug() <<"RELAY_COLD off"<<endl;
             arguments="COLD";
             break;
        case RELAYS_COLD_AND_HOT:
             qDebug() <<"RELAYS_COLD_AND_HOT off"<<endl;
             arguments="COLD_AND_HOT";
             break;
        default:
             arguments="";
             break;
    }

    QProcess relayProcess;

    relayProcess.start("./relaysOff", QStringList() << arguments);
    if (!relayProcess.waitForStarted())
        return ;


    if (!relayProcess.waitForFinished())
        return ;



}//end func
