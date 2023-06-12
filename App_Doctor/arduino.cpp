#include "arduino.h"

// Constructor for the Arduino class, takes a baud rate as input
Arduino::Arduino( int baudRate)
{

    isArduinoAvailable=false;

    // Create a new QSerialPort object
    arduino = new QSerialPort();

    QSerialPortInfo portToUse;
      // Iterate through all available serial ports
      foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
      {
          QString s = QObject::tr("Port:") + info.portName() + "\n"
                      + QObject::tr("Location:") + info.systemLocation() + "\n"
                      + QObject::tr("Description:") + info.description() + "\n"
                      + QObject::tr("Manufacturer:") + info.manufacturer() + "\n"
                      + QObject::tr("Serial number:") + info.serialNumber() + "\n"
                      + QObject::tr("Vendor Identifier:") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
                      + QObject::tr("Product Identifier:") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n"
                      + QObject::tr("Busy:") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";

          // Check if the port is not busy and if it is an Arduino based on the description or manufacturer
          // If it matches, assign it to the portToUse variable
          // Commented out the if condition to use the last found port that matches the criteria
          //if(!info.isBusy() && (info.description().contains("Arduino") || info.manufacturer().contains("Arduino")))
              portToUse = info;

      }
    // If no suitable port is found, return
      if(portToUse.isNull() || !portToUse.isValid())
      {

          return;
      }



      // Enumerate the serial port
      // Find one that sounds like Arduino, or the highest one on the list
      // Open it if it isn't busy

      arduino->setPortName(portToUse.portName());
      arduino->setBaudRate(baudRate);
      arduino->setDataBits(QSerialPort::Data8);
      arduino->setParity(QSerialPort::NoParity);
      arduino->setStopBits(QSerialPort::OneStop);
      arduino->setFlowControl(QSerialPort::NoFlowControl);
      if (arduino->open(QIODevice::ReadWrite)) {

          QThread::msleep(5000);
          isArduinoAvailable=true;
      }

}
// Check if the Arduino is ready and available
bool Arduino::isReady(){
    return isArduinoAvailable;
}
// Read a line of data from the Arduino
QString Arduino::readLine(){
    // Keep reading until a complete line is available
      while(arduino->canReadLine()==false){
        // Wait for up to 20 seconds for data to be available for reading
          if(arduino->waitForReadyRead(20000)==false)
              return "";

      }

      return arduino->readLine();


}

// Write a single character to the Arduino
void Arduino::writeChar(char c){
    arduino->write(&c,1); // Write the character to the Arduino
    arduino->waitForBytesWritten(); // Wait for the bytes to be written to the Arduino

}
