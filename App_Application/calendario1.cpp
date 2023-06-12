#include "calendario1.h"
#include "ui_calendario1.h"

calendario1::calendario1(QWidget *parent, int day, int hour, int minutos, int mes) :
    QDialog(parent),
    ui(new Ui::calendario1)
{
    ui->setupUi(this);
    if (hour>=12)
    {
        hour=hour-12;
        ui->label->setText("Muestra programada para el día "+QString::number(day)+" del mes "+QString::number(mes)+" a las "+QString::number(hour)+":"+QString::number(minutos)+" PM");
    }else{
    ui->label->setText("Muestra programada para el día "+QString::number(day)+" del mes "+QString::number(mes)+" a las "+QString::number(hour)+":"+QString::number(minutos)+" AM");

    }
}


calendario1::~calendario1()
{
    delete ui;
}

void calendario1::on_buttonBox_accepted()
{

}
