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
    // Constructor for the Arduino class
    Arduino(int baudRate);

    // Check if the Arduino is ready and available
    bool isReady();

    // Close the serial port connection
    void close(void);

    // Read a line of data from the Arduino
    QString readLine();

    // Write a character to the Arduino
    void writeChar(char c);

private:
    QSerialPort *arduino;
    bool isArduinoAvailable;

    // Vendor identifiers for different Arduino boards
    static const quint16 arduinoUNO = 66;
    static const quint16 arduinoMEGA = 67;
};

#endif // ARDUINO_H
