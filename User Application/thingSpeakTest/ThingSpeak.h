/*
ThingSpeak access by using Qt

Alexander López-Parrado PhD (2020)
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
    int channel;
    QString wKey;
    QString rKey;
    QNetworkAccessManager *manager;



public:
    ThingSpeak(int channeli,QString wKeyi,QString rKeyi);
    ~ThingSpeak();


    QString SendData(QVector <double>fieldArray);
    QString SendData(QVector <QString>fieldArray);
    QString SendData(int field,double value);
    QString SendData(int field,QString value);
    QString RecvData();
    QString RecvData(int field);

};
