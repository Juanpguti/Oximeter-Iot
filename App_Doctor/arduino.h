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
    Arduino( int baudRate); // Constructor for the Arduino class, takes a baud rate as input

   bool isReady();

   QString readLine();
   void writeChar(char c);
private:
    QSerialPort *arduino;
    bool isArduinoAvailable;

    // Constants for Arduino board types
    static const quint16 arduinoUNO = 66;
    static const quint16 arduinoMEGA = 67;
};

#endif // ARDUINO_H
