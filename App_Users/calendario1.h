#ifndef CALENDARIO1_H
#define CALENDARIO1_H

#include <QDialog>

namespace Ui {
class calendario1;
}

class calendario1 : public QDialog
{
    Q_OBJECT

public:
    // Constructor for the calendario1 class
    explicit calendario1(QWidget *parent = nullptr, int day = 0, int hour = 0, int minutos = 0, int mes = 0);

    // Destructor for the calendario1 class
    ~calendario1();

private slots:
    // Slot for the accepted button in the button box
    void on_buttonBox_accepted();

private:
    Ui::calendario1 *ui;
};

#endif // CALENDARIO1_H
