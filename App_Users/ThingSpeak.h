// defines
#define URL_THINGSPEAK             "https://api.thingspeak.com/"
#define BEGIN_OF_HTTP_REQ_WRITE    "update?api_key="
#define BEGIN_OF_HTTP_REQ_READ     "channels"

#include <QtNetwork/QNetworkAccessManager> // Include the QNetworkAccessManager header
#include <QtNetwork/QNetworkReply> // Include the QNetworkReply header
#include <QEventLoop> // Include the QEventLoop header


class ThingSpeak {

private:
    int channel;
    QString wKey;
    QString rKey;
    QNetworkAccessManager *manager;

public:
    ThingSpeak(int channeli, QString wKeyi, QString rKeyi);
    ~ThingSpeak();

    QString SendData(QVector<double> fieldArray); // Send data to ThingSpeak using a vector of double values
    QString SendData(QVector<QString> fieldArray); // Send data to ThingSpeak using a vector of QString values
    QString SendData(int field, double value); // Send data to ThingSpeak for a specific field using a double value
    QString SendData(int field, QString value); // Send data to ThingSpeak for a specific field using a QString value
    QString RecvData(); // Receive data from ThingSpeak
    QString RecvData(int field); // Receive data from a specific field in ThingSpeak

};
