#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "readtemp.h"
#include "pidcontroller.h"
#include "relays.h"
#include <QSettings>

class ReadTemp;
class PIDController;
class Relays;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_pressed();
    void on_pushButtonSetTemperature_pressed();
    void UpdateData(float value , bool error);

    void on_pushButtonSaveparams_pressed();

    void on_dial_valueChanged(int value);

    void on_pushButtonLoadPID_pressed();

    void updateGUIparametersPID();

private:
    Ui::MainWindow *ui;
    ReadTemp *readTemperature;
    PIDController *pidController;
    Relays *relays;
    QString m_sSettingsFile;

    void getSetupParameters();
    void saveSetupParameters();
    qint32 dialValue;
    qint32 pastDialValue;

    QSettings *_sysIniFile;

    float P;
    float I;
    float D;
    float IntegralThreshold;
    float DriveThreshold;


};

#endif // MAINWINDOW_H
