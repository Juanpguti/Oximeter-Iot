#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user1.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QTimer>
#include "ui_user1.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerfin()));
    timer->start(15000);
    setWindowTitle("Proyecto CDIO I");
    ui->tabWidget->setCurrentIndex(0);
    setWindowTitle("D-Iotech");
    //manager = new QNetworkAccessManager(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tab_5_customContextMenuRequested(const QPoint &pos)
{

}

void MainWindow::on_tab_5_windowIconTextChanged(const QString &iconText)
{

}
//Usuario 1
void MainWindow::on_pushButton_3_clicked()
{
    User1 *u1;
    u1=new User1(this,1167232,"V5AQRWNPXTZZKFXU","3F9SQL68VM51F36Z");
    u1->show();
}

//Usuario 2
void MainWindow::on_pushButton_4_clicked()
{
    User1 *u1;
    u1=new User1(this,1226428,"UWGPMLIJKHCEGV4D","ZR6F5MGJ2U5CAT1A");
    u1->show();
}

//Usuario 3
void MainWindow::on_pushButton_5_clicked()
{
    User1 *u1;
    u1=new User1(this,1232035,"Y0W0XPCN7264ZYN1","DAAMAXYBSGLYAHKR");
    u1->show();
}

//Usuario 4
void MainWindow::on_pushButton_6_clicked()
{
    User1 *u1;
    u1=new User1(this,1232036,"SH18TLSOHNCWRUBI","G3THE8UDBOKWPE8I");
    u1->show();
}

void MainWindow :: timerfin()
{
    //Ts= new ThingSpeak(Chanel,Escritura,Lectura);
    //Usuario 1
    ThingSpeak *Ts=new ThingSpeak(1167232,"3F9SQL68VM51F36Z","V5AQRWNPXTZZKFXU");
    QString Al = Ts->RecvData(6);

    if(Al.toInt()==1)
    {
        Ts->SendData(6,"0");
        QMessageBox::about(this,"Usuario 1","Tiene nuevas lecturas");

    }
    //Usuario 2
    ThingSpeak *Ts2= new ThingSpeak(1226428,"ZR6F5MGJ2U5CAT1A","UWGPMLIJKHCEGV4D");
    QString Al2 = Ts2->RecvData(6);

    if(Al2.toInt()==1)
    {
        Ts2->SendData(6,"0");
        QMessageBox::about(this,"Usuario 2","Tiene nuevas lecturas");
    }
    //Usuario 3
    ThingSpeak *Ts3= new ThingSpeak(1232035,"DAAMAXYBSGLYAHKR","Y0W0XPCN7264ZYN1");
    QString Al3 = Ts3->RecvData(6);

    if(Al3.toInt()==1)
    {
        Ts3->SendData(6,"0");
        QMessageBox::about(this,"Usuario 3","Tiene nuevas lecturas");
    }
    //Usuario 4
    ThingSpeak *Ts4= new ThingSpeak(1232036,"G3THE8UDBOKWPE8I","SH18TLSOHNCWRUBI");
    QString Al4 = Ts4->RecvData(6);

    if(Al4.toInt()==1)
    {
        Ts4->SendData(6,"0");
        QMessageBox::about(this,"Usuario 4","Tiene nuevas lecturas");
    }
}



