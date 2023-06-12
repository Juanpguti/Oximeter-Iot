#ifndef USER1_H
#define USER1_H
#include <arduino.h>
#include <QDialog>
#include <ThingSpeak.h>

namespace Ui {
class User1;
}

class User1 : public QDialog
{
    Q_OBJECT

public:
    explicit User1(QWidget *parent ,int Chanel,QString Lectura,QString Escritura);
    ~User1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void closeEvent (QCloseEvent *event);

private:
    Ui::User1 *ui;
    Arduino *arduino;
    ThingSpeak *Ts;
    QString str1,str2,str3;
};

#endif // USER1_H
