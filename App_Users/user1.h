#ifndef USER1_H
#define USER1_H

#include <arduino.h> // Include the Arduino header
#include <QDialog>
#include <ThingSpeak.h> // Include the ThingSpeak header

namespace Ui {
class User1;
}

class User1 : public QDialog
{
    Q_OBJECT

public:
    explicit User1(QWidget *parent, int Chanel, QString Lectura, QString Escritura);
    ~User1();

private slots:
    void on_pushButton_clicked(); // Slot for the pushButton click

    void on_pushButton_3_clicked(); // Slot for the pushButton_3 click

    void on_pushButton_2_clicked(); // Slot for the pushButton_2 click

    void on_pushButton_4_clicked(); // Slot for the pushButton_4 click

    void closeEvent(QCloseEvent *event); // Slot for the close event

private:
    Ui::User1 *ui;
    Arduino *arduino; // Pointer to an Arduino object
    ThingSpeak *Ts; // Pointer to a ThingSpeak object
    QString str1, str2, str3; // Strings for storage
};

#endif // USER1_H
