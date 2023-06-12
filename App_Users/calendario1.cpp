#include "calendario1.h"
#include "ui_calendario1.h"

// Constructor for the calendario1 class
calendario1::calendario1(QWidget *parent, int day, int hour, int minutos, int mes) :
    QDialog(parent),
    ui(new Ui::calendario1)
{
    ui->setupUi(this);

    // Check if the hour is greater than or equal to 12 to determine whether it's AM or PM
    if (hour >= 12)
    {
        hour = hour - 12;
        ui->label->setText("Muestra programada para el día " + QString::number(day) + " del mes " + QString::number(mes) + " a las " + QString::number(hour) + ":" + QString::number(minutos) + " PM");
    }
    else
    {
        ui->label->setText("Muestra programada para el día " + QString::number(day) + " del mes " + QString::number(mes) + " a las " + QString::number(hour) + ":" + QString::number(minutos) + " AM");
    }
}

// Destructor for the calendario1 class
calendario1::~calendario1()
{
    delete ui;
}

void calendario1::on_buttonBox_accepted()
{
    // Implementation for the accepted button in the button box
    // You can add your own code here if needed
}
