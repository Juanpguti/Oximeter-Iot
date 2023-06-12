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
    explicit User1(QWidget *parent ,int Chanel,QString Lectura,QString Escritura); // Constructor
    ~User1(); // Destructor

private slots:

    void on_pushButton_3_clicked(); // Slot for button 3 click event

    void on_pushButton_4_clicked(); // Slot for button 4 click event

    void on_label_linkActivated(const QString &link); // Slot for label link activation event

private:
    Ui::User1 *ui;   // User interface for User1 class
    Arduino *arduino;  // Pointer to Arduino object
    ThingSpeak *Ts;  // Pointer to ThingSpeak object
    ThingSpeak *Ts2;  // Pointer to additional ThingSpeak object (Ts2)
    ThingSpeak *Ts3; // Pointer to additional ThingSpeak object (Ts3)
    ThingSpeak *Ts4; // Pointer to additional ThingSpeak object (Ts4)
    QString str1,str2,str3; // Strings for storing data
};

#endif // USER1_H
