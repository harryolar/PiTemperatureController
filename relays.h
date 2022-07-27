#ifndef RELAYS_H
#define RELAYS_H

#include <QObject>


class Relays : public QObject
{
    Q_OBJECT
public:
    explicit Relays(QObject *parent = 0);
    
    enum RELAYS_STATE
    {
        RELAY_HOT,
        RELAY_COLD,
        RELAYS_COLD_AND_HOT

    };

signals:
    
public slots:
    void RelaysSetOn(RELAYS_STATE  state);
    void RelaysSetOff(RELAYS_STATE state);

private:

};

#endif // RELAYS_H
