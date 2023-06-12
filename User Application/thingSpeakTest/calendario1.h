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
    explicit calendario1(QWidget *parent = nullptr,int day=0,int hour=0, int minutos=0, int mes=0);

    ~calendario1();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::calendario1 *ui;
};

#endif // CALENDARIO1_H
