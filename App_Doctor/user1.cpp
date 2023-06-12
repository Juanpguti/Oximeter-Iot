#include "user1.h"
#include "ui_user1.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>


User1::User1(QWidget *parent,int Chanel,QString Lectura,QString Escritura) :
    QDialog(parent),
    ui(new Ui::User1)
{
 //Crea el objeto tipo Arduino para una velocidad de 115200 bps
    arduino=new Arduino(115200);
    ui->setupUi(this);
    Ts= new ThingSpeak(Chanel,Escritura,Lectura);

     if (Chanel==1167232){
         ui->label_3->setText("Usuario 1");
     }else if (Chanel==1226428){
         ui->label_3->setText("Usuario 2");
     }else if (Chanel==1232035){
         ui->label_3->setText("Usuario 3");
    }else if (Chanel==1232036){
         ui->label_3->setText("Usuario 4");
    }
}

User1::~User1()
{
    delete ui;
}

//Recibe Datos
void User1::on_pushButton_3_clicked()
{

    QVector<QString> data;
    str1=Ts->RecvData(1);
    str2=Ts->RecvData(2);
    str3=Ts->RecvData(3);

    ui->lcdNumber_6->display(str1.toDouble());
    ui->lcdNumber_5->display(str2.toDouble());
    ui->lcdNumber_4->display(str3.toDouble());


    //Temperatura
     if (str1.toDouble()>37){
          ui->lcdNumber_6->setPalette(Qt::red);
       }else {
           ui->lcdNumber_6->setPalette(Qt::green);
         }
    //Oximetria
       if (str2.toDouble()>100){
          ui->lcdNumber_5->setPalette(Qt::red); //rojo
       }else if (str2.toDouble()<90)
       {
          ui->lcdNumber_5->setPalette(Qt::red); //rojo
       } else
        {
          ui->lcdNumber_5->setPalette(Qt::green); //verde
        }
       //Ritmo Cardiaco
       if (str3.toDouble()>100){
          ui->lcdNumber_4->setPalette(Qt::red); //rojo
       }else if (str3.toDouble()<60)
       {
          ui->lcdNumber_4->setPalette(Qt::red); //rojo
       } else
        {
          ui->lcdNumber_4->setPalette(Qt::green); //verde
        }
}

void User1::on_pushButton_4_clicked()
{
    Ts->SendData(4,ui->oxiSend->text());
    ui->label_2->setText(Ts->RecvData(4));

}

