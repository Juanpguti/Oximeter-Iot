/*
ThingSpeak access by using Qt
*/

//defines
#define URL_THINGSPEAK             "https://api.thingspeak.com/"
#define BEGIN_OF_HTTP_REQ_WRITE         "update?api_key="
#define BEGIN_OF_HTTP_REQ_READ         "channels"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>


class ThingSpeak{


private:
    int channel; // Channel number for sending and receiving data
    QString wKey; // Write key for sending data
    QString rKey; // Read key for receiving data
    QNetworkAccessManager *manager; // Qt network access manager



public:
    ThingSpeak(int channeli,QString wKeyi,QString rKeyi); // Class constructor
    ~ThingSpeak(); // Class destructor


    QString SendData(QVector <double>fieldArray);  // Method to send double data to ThingSpeak
    QString SendData(QVector <QString>fieldArray); // Method to send QString data to ThingSpeak
    QString SendData(int field,double value);  // Method to send a single double data to ThingSpeak
    QString SendData(int field,QString value);  // Method to send a single QString data to ThingSpeak
    QString RecvData();  // Method to receive the latest entry from ThingSpeak
    QString RecvData(int field); // Method to receive the latest entry from a specific field in ThingSpeak

};
