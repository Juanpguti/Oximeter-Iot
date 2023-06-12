/*
ThingSpeak access by using Qt
*/


#include "ThingSpeak.h"


//Name space for C++ standard library
using namespace std;

ThingSpeak::ThingSpeak(int channeli,QString wKeyi,QString rKeyi){
    channel=channeli;
    wKey=wKeyi;
    rKey=rKeyi;
    manager = new QNetworkAccessManager();
}

ThingSpeak::~ThingSpeak(){
    delete manager;
}


/*Method to send data to ThingSpeak*/
QString ThingSpeak::SendData(QVector <double>fieldArray)
{


    int i;

    char ThingSpeakURL[]=URL_THINGSPEAK;
    char BeginOfHTTPReq[]=BEGIN_OF_HTTP_REQ_WRITE;


    QString url="";


    if (fieldArray.size()<=0)
        return QString("PARAMS_ERROR");



    url.append(ThingSpeakURL);
    url.append(BeginOfHTTPReq+wKey);


    for(i=1; i<= fieldArray.size(); i++)
    {
        url.append("&field");
        url.append(QString::number(i)+"=");
        url.append(QString::number(fieldArray[i-1]));
    }

    QEventLoop loop;
    QNetworkReply *reply=manager->get(QNetworkRequest(url));


    QObject::connect(reply,&QNetworkReply::finished,&loop,&QEventLoop::quit);

    loop.exec();

    return reply->readLine();

}

/*Method to send data to ThingSpeak*/
QString ThingSpeak::SendData(QVector <QString>fieldArray)
{


    int i;

    char ThingSpeakURL[]=URL_THINGSPEAK;
    char BeginOfHTTPReq[]=BEGIN_OF_HTTP_REQ_WRITE;


    QString url="";


    if (fieldArray.size()<=0)
        return QString("PARAMS_ERROR");



    url.append(ThingSpeakURL);
    url.append(BeginOfHTTPReq+wKey);


    for(i=1; i<= fieldArray.size(); i++)
    {
        url.append("&field");
        url.append(QString::number(i)+"=");
        url.append(fieldArray[i-1]);
    }

    QEventLoop loop;
    QNetworkReply *reply=manager->get(QNetworkRequest(url));


    QObject::connect(reply,&QNetworkReply::finished,&loop,&QEventLoop::quit);

    loop.exec();

    return reply->readLine();

}

/*Method to send data to ThingSpeak*/
QString ThingSpeak::SendData(int field,double value)
{


    char ThingSpeakURL[]=URL_THINGSPEAK;
    char BeginOfHTTPReq[]=BEGIN_OF_HTTP_REQ_WRITE;


    QString url="";


    if (field<1)
        return QString("PARAMS_ERROR");



    url.append(ThingSpeakURL);
    url.append(BeginOfHTTPReq+wKey);




        url.append("&field");
        url.append(QString::number(field)+"=");
        url.append(QString::number(value));


    QEventLoop loop;
    QNetworkReply *reply=manager->get(QNetworkRequest(url));


    QObject::connect(reply,&QNetworkReply::finished,&loop,&QEventLoop::quit);

    loop.exec();

    return reply->readLine();

}

/*Method to send data to ThingSpeak*/
QString ThingSpeak::SendData(int field,QString value)
{


    char ThingSpeakURL[]=URL_THINGSPEAK;
    char BeginOfHTTPReq[]=BEGIN_OF_HTTP_REQ_WRITE;


    QString url="";


    if (field<1)
        return QString("PARAMS_ERROR");



    url.append(ThingSpeakURL);
    url.append(BeginOfHTTPReq+wKey);




        url.append("&field");
        url.append(QString::number(field)+"=");
        url.append(value);


    QEventLoop loop;
    QNetworkReply *reply=manager->get(QNetworkRequest(url));


    QObject::connect(reply,&QNetworkReply::finished,&loop,&QEventLoop::quit);

    loop.exec();

    return reply->readLine();

}



/*Method to read last entry from ThingSpeak*/
QString ThingSpeak::RecvData()
{


    char ThingSpeakURL[]=URL_THINGSPEAK;
    char BeginOfHTTPReq[]=BEGIN_OF_HTTP_REQ_READ;


    QString url="";

    url.append(ThingSpeakURL);
    url.append(BeginOfHTTPReq);
    url.append("/");
    url.append(QString::number(channel));
    url.append("/feeds/last?api_key=");
    url.append(rKey);

    QEventLoop loop;
    QNetworkReply *reply=manager->get(QNetworkRequest(url));


    QObject::connect(reply,&QNetworkReply::finished,&loop,&QEventLoop::quit);

    loop.exec();



    return reply->readLine();







}


/*Method to read last entry from ThingSpeak*/
QString ThingSpeak::RecvData(int field)
{


    char ThingSpeakURL[]=URL_THINGSPEAK;
    char BeginOfHTTPReq[]=BEGIN_OF_HTTP_REQ_READ;


    QString url="";

    url.append(ThingSpeakURL);
    url.append(BeginOfHTTPReq);
    url.append("/");
    url.append(QString::number(channel));
    url.append("/fields/"+QString::number(field)+"/last?api_key=");
    url.append(rKey);

    QEventLoop loop;
    QNetworkReply *reply=manager->get(QNetworkRequest(url));


    QObject::connect(reply,&QNetworkReply::finished,&loop,&QEventLoop::quit);

    loop.exec();



    return reply->readLine();







}


