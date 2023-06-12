#include "user1.h"
#include "ui_user1.h"
#include "calendario1.h"


User1::User1(QWidget *parent,int Chanel,QString Lectura,QString Escritura) :
    QDialog(parent),
    ui(new Ui::User1)
{
 //Crea el objeto tipo Arduino para una velocidad de 115200 bps
    arduino=new Arduino(115200);
    ui->setupUi(this);
    Ts= new ThingSpeak(Chanel,Escritura,Lectura);

     if (arduino->isReady()){
         ui->pushButton_3->setEnabled(true);
         ui->label->setStyleSheet("QLabel { background-color : green; color : white; }");
         ui->label->setText(" Dispositivo encontrado");
     }
     else{
         ui->pushButton_3->setEnabled(false);
         ui->label->setStyleSheet("QLabel { background-color : red; color : black; }");
         ui->label->setText(" Dispositivo no encontrado");

     }
     if (Chanel==1167232){
         ui->label_3->setText("Usuario 1");
     }else if (Chanel==1226428){
         ui->label_3->setText("Usuario 2");
     }else if (Chanel==1232035){
         ui->label_3->setText("Usuario 3");
    }else if (Chanel==1232036){
         ui->label_3->setText("Usuario 4");
    }
    ui->label_6->setText(Ts->RecvData(5));

}

User1::~User1()
{
        delete ui;
}

// Calendario
void User1::on_pushButton_clicked()
{
    int h, minutos, mes;
    calendario1 *cal1;
    QDate fecha= ui->calendarWidget->selectedDate();
    QTime hora = ui->timeEdit->time();
    minutos= hora.minute();
    mes=fecha.month(); //retorna un número
    cal1=new calendario1(this,fecha.day(),hora.hour(),hora.minute(),fecha.month());
    cal1-> show();
    h=hora.hour();
    if (h>12){
    h=h-12;
    Ts->SendData(5,"Muestra pendiente para el día "+QString::number(fecha.day())+" del mes "+QString::number(mes)+" a las "+QString::number(h)+":"+QString::number(minutos)+" PM");
    }else{
    Ts->SendData(5,"Muestra pendiente para el día "+QString::number(fecha.day())+" del mes "+QString::number(mes)+" a las "+QString::number(h)+":"+QString::number(minutos)+" AM");
    }
    ui->label_6->setText(Ts->RecvData(5));
 }
//Recibe Datos
void User1::on_pushButton_3_clicked()
{


    //Envía un dato al Arduino para solicitar una medida del sensor
      arduino->writeChar(0);
      //Lee tres líneas desde el Arduino
       str1=arduino->readLine();
       str2=arduino->readLine();
       str3=arduino->readLine();
       if (str1.toDouble()>=38){
          ui->lcdNumber_6->setPalette(Qt::red); //rojo
       }else {
           ui->lcdNumber_6->setPalette(Qt::green); //verde
         }
       if (str2.toDouble()<90){
          ui->lcdNumber_5->setPalette(Qt::red); //rojo
       }else if (str2.toDouble()>100)
       {
          ui->lcdNumber_5->setPalette(Qt::red); //rojo
       } else
        {
          ui->lcdNumber_5->setPalette(Qt::green); //verde
        }
       if (str3.toDouble()<60){
          ui->lcdNumber_4->setPalette(Qt::red); //rojo
       }else if (str3.toDouble()>100)
       {
          ui->lcdNumber_4->setPalette(Qt::red); //rojo
       } else
        {
          ui->lcdNumber_4->setPalette(Qt::green); //verde
        }
       ui->lcdNumber_6->display(str1.toDouble());
       ui->lcdNumber_5->display(str2.toDouble());
       ui->lcdNumber_4->display(str3.toDouble());

}

// Envía Datos
void User1::on_pushButton_2_clicked()
{
       QVector<QString> data;
       data.append(str1);
        data.append(str2);
        data.append(str3);
        data.append(nullptr); // <-- médico
        data.append(nullptr); // <-- recordatorio #5
        data.append("1");
        Ts->SendData(data);
        // Para extraer datos readData(#campoquequieroleer(4))


}

void User1::on_pushButton_4_clicked()
{
    // Mostrar mensaje del médico
    ui->label_2->setText(Ts->RecvData(4));

    // Mostrar Recordatorio al Usuario_n
    //ui->label_6->setText(Ts->RecvData(5));

}

void User1::closeEvent (QCloseEvent *event){
      arduino->close();
}
