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
 // Create Arduino object with a baud rate of 115200 bps
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

// Receive Data
void User1::on_pushButton_3_clicked()
{

    QVector<QString> data;
    str1=Ts->RecvData(1); // Receive data from ThingSpeak field 1
    str2=Ts->RecvData(2); // Receive data from ThingSpeak field 2
    str3=Ts->RecvData(3); // Receive data from ThingSpeak field 3

    ui->lcdNumber_6->display(str1.toDouble()); // Display the received value on LCD Number 6
    ui->lcdNumber_5->display(str2.toDouble()); // Display the received value on LCD Number 5
    ui->lcdNumber_4->display(str3.toDouble()); // Display the received value on LCD Number 4


    // Temperature
     if (str1.toDouble()>37){
          ui->lcdNumber_6->setPalette(Qt::red); // Set the palette to red if temperature is above 37
       }else {
           ui->lcdNumber_6->setPalette(Qt::green);  // Set the palette to green if temperature is below or equal to 37
         }
    // Oxygen Level
       if (str2.toDouble()>100){
          ui->lcdNumber_5->setPalette(Qt::red); //red
       }else if (str2.toDouble()<90)
       {
          ui->lcdNumber_5->setPalette(Qt::red); //red
       } else
        {
          ui->lcdNumber_5->setPalette(Qt::green); //green
        }
       // Heart Rate
       if (str3.toDouble()>100){
          ui->lcdNumber_4->setPalette(Qt::red); //red
       }else if (str3.toDouble()<60)
       {
          ui->lcdNumber_4->setPalette(Qt::red); //red
       } else
        {
          ui->lcdNumber_4->setPalette(Qt::green); //green
        }
}

void User1::on_pushButton_4_clicked()
{
    Ts->SendData(4,ui->oxiSend->text()); // Send data from the text input to ThingSpeak field 4
    ui->label_2->setText(Ts->RecvData(4)); // Receive and display data from ThingSpeak field 4

}

