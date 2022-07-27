#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readtemp.h"
#include <QObject>
#include <QSettings>
#include <QApplication>
#include <QDebug>

//******************************************************************************
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
//******************************************************************************
{
    ui->setupUi(this);

    IntegralThreshold=5;
    DriveThreshold=2;

    m_sSettingsFile = QApplication::applicationDirPath()+ "/config.ini";

     qDebug() << "Config.ini path =" << m_sSettingsFile<<endl;

     _sysIniFile = new QSettings(m_sSettingsFile, QSettings::IniFormat, 0);

     getSetupParameters();
     updateGUIparametersPID();

    readTemperature= new ReadTemp();
    pidController= new PIDController();
    pidController->PIDInit(P , I ,D , IntegralThreshold,DriveThreshold);
    pidController->setSetTemperature(0.0);


    relays= new Relays();

    connect(readTemperature ,SIGNAL(ReadDataReady(float,bool)),this,SLOT(UpdateData(float,bool)));
    connect(readTemperature ,SIGNAL(ReadDataReady(float,bool)),pidController,SLOT(PIDTask(float,bool)));

    readTemperature->ReadStart(500);

    dialValue=0;
    pastDialValue=0;

}//end func

//******************************************************************************
MainWindow::~MainWindow()
//******************************************************************************
{
    delete ui;
}//end func

//set PID
//******************************************************************************
void MainWindow::on_pushButton_pressed()
//******************************************************************************
{
    bool test;
    float P_Param;
    float I_Param;
    float D_Param;

    P_Param = ui->lineEditP->text().toFloat(&test);
    if(test == false)
    {
       qDebug() <<" P value not valid"<<endl;

    }
    else
    {
         P=P_Param;
    }

    I_Param = ui->lineEditI->text().toFloat(&test);

    if(test == false)
    {
       qDebug() <<" I value not valid"<<endl;
    }
    else
    {
         I=I_Param;
    }

    D_Param = ui->lineEditD->text().toFloat(&test);

    if(test == false)
    {
       qDebug() <<" D value not valid"<<endl;
    }
    else
    {
         D=D_Param;
    }

     pidController->PIDInit(P , I ,D , IntegralThreshold,DriveThreshold);

}//end func

//******************************************************************************
void MainWindow::on_pushButtonSetTemperature_pressed()
//******************************************************************************
{
    bool test;
    float temperature;


    temperature = ui->lineEditSetTemperature->text().toFloat(&test);
    if(test == false)
    {
       qDebug() <<" Temperature value not valid" <<temperature <<endl;

    }
    else
    {
         pidController->setSetTemperature(temperature);
    }



}//end func

//******************************************************************************
void MainWindow::UpdateData(float value, bool error)
//******************************************************************************
{
    ui->lcdNumber->display( value);


}//end func


//******************************************************************************
void MainWindow::getSetupParameters()
//******************************************************************************
{

    bool test;


    P = _sysIniFile->value("P").toFloat(&test);
    if(test == false)
    {
       qDebug() <<" config.ini P value failed to load"<<endl;
    }
    else
    {
       qDebug() <<" config.ini P value is" <<P<<endl;
    }

    I = _sysIniFile->value("I").toFloat(&test);
    if(test == false)
    {
       qDebug() <<" config.ini I value failed to load"<<endl;
    }
    else
    {
       qDebug() <<" config.ini I value is" <<I<<endl;
    }

    D = _sysIniFile->value("D").toFloat(&test);
    if(test == false)
    {
       qDebug() <<" config.ini I value failed to load"<<endl;
    }
    else
    {
       qDebug() <<" config.ini D value is" << D <<endl;
    }

    IntegralThreshold = _sysIniFile->value("IntegralThreshold").toFloat(&test);
    if(test == false)
    {
       qDebug() <<" config.ini IntegralThreshold value failed to load"<<endl;
    }
    else
    {
       qDebug() <<" config.ini IntegralThreshold value is" << IntegralThreshold <<endl;
    }

    DriveThreshold= _sysIniFile->value("DriveThreshold").toFloat(&test);
    if(test == false)
    {
       qDebug() <<" config.ini DriveThreshold value failed to load"<<endl;
    }
    else
    {
       qDebug() <<" config.ini DriveThreshold value is" << DriveThreshold <<endl;
    }


}//end func

//******************************************************************************
void MainWindow::saveSetupParameters()
//******************************************************************************
{

    bool test;
    float P_Param;
    float I_Param;
    float D_Param;

    P_Param = ui->lineEditP->text().toFloat(&test);
    if(test == false)
    {
       qDebug() <<" P value not valid"<<endl;

    }
    else
    {
         P=P_Param;
    }

    I_Param = ui->lineEditI->text().toFloat(&test);

    if(test == false)
    {
       qDebug() <<" I value not valid"<<endl;
    }
    else
    {
         I=I_Param;
    }

    D_Param = ui->lineEditD->text().toFloat(&test);

    if(test == false)
    {
       qDebug() <<" D value not valid"<<endl;
    }
    else
    {
         D=D_Param;
    }

    _sysIniFile->setValue("P", QString::number(P));
    _sysIniFile->setValue("I", QString::number(I));
    _sysIniFile->setValue("D", QString::number(D));
    _sysIniFile->sync();

}//end func


//******************************************************************************
void MainWindow::on_pushButtonSaveparams_pressed()
//******************************************************************************
{
    saveSetupParameters();
}

//******************************************************************************
void MainWindow::on_dial_valueChanged(int value)
//******************************************************************************
{
    float finalValue;
    int tempValue;

    tempValue = value   - pastDialValue;


    if(tempValue < 10 && tempValue > -10)
    {
          dialValue += tempValue ;
    }
    qDebug() << "Dial Value" <<dialValue <<" Temp value=" << tempValue <<endl;



    pastDialValue=value;
    finalValue = dialValue *0.5;

    ui->lineEditSetTemperature->setText( QString::number(finalValue));
    //pidController -> setSetTemperature((float)value);
}

//******************************************************************************
void MainWindow::on_pushButtonLoadPID_pressed()
//******************************************************************************
{
    getSetupParameters();
    updateGUIparametersPID();
}

//******************************************************************************
void MainWindow::updateGUIparametersPID()
//******************************************************************************
{
    ui->lineEditP->setText(QString::number(P));
    ui->lineEditI->setText(QString::number(I));
    ui->lineEditD->setText(QString::number(D));
}
