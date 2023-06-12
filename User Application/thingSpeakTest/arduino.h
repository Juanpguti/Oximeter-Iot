#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>
#include <QDebug>
#include <QCoreApplication>

class Arduino
{
public:
    Arduino( int baudRate);

   bool isReady();
   void close(void);

   QString readLine();
   void writeChar(char c);
private:
    QSerialPort *arduino;
    bool isArduinoAvailable;


    static const quint16 arduinoUNO = 66;
    static const quint16 arduinoMEGA = 67;
};

#endif // ARDUINO_H
