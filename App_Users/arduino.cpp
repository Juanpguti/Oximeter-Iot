#include "arduino.h"

// Constructor for the Arduino class
Arduino::Arduino(int baudRate)
{
    isArduinoAvailable = false;
    arduino = new QSerialPort();

    QSerialPortInfo portToUse;

    // Iterate through available serial ports
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        // Gather information about the serial port
        QString s = QObject::tr("Port:") + info.portName() + "\n"
                    + QObject::tr("Location:") + info.systemLocation() + "\n"
                    + QObject::tr("Description:") + info.description() + "\n"
                    + QObject::tr("Manufacturer:") + info.manufacturer() + "\n"
                    + QObject::tr("Serial number:") + info.serialNumber() + "\n"
                    + QObject::tr("Vendor Identifier:") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
                    + QObject::tr("Product Identifier:") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n"
                    + QObject::tr("Busy:") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";

        // Check if the port is not busy and has a specific vendor identifier
        if (!info.isBusy() && (info.vendorIdentifier() == 0x2341))
            portToUse = info;
    }

    // If no suitable port is found, return from the constructor
    if (portToUse.isNull() || !portToUse.isValid())
    {
        return;
    }

    // Set the port name and other configurations for the serial port
    arduino->setPortName(portToUse.portName());
    arduino->setBaudRate(baudRate);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    // Open the serial port for reading and writing
    if (arduino->open(QIODevice::ReadWrite))
    {
        QThread::msleep(5000); // Delay for 5 seconds
        isArduinoAvailable = true;
    }
}

// Check if the Arduino is ready and available
bool Arduino::isReady()
{
    return isArduinoAvailable;
}

// Read a line of data from the Arduino
QString Arduino::readLine()
{
    while (arduino->canReadLine() == false)
    {
        // Wait for data to be available for reading
        if (arduino->waitForReadyRead() == false)
            return "";
    }

    // Read and return a line from the Arduino
    return arduino->readLine();
}

// Write a character to the Arduino
void Arduino::writeChar(char c)
{
    arduino->write(&c, 1);
    arduino->waitForBytesWritten();
}

// Close the serial port connection
void Arduino::close()
{
    arduino->close();
}
