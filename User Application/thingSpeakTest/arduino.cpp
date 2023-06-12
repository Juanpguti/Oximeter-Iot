#include "arduino.h"



Arduino::Arduino( int baudRate)
{

    isArduinoAvailable=false;


    arduino = new QSerialPort();

    QSerialPortInfo portToUse;
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

              if(!info.isBusy() && (info.vendorIdentifier()==0x2341))
              portToUse = info;

      }

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

bool Arduino::isReady(){
    return isArduinoAvailable;
}

QString Arduino::readLine(){

      while(arduino->canReadLine()==false){

          if(arduino->waitForReadyRead()==false)
              return "";

      }

      return arduino->readLine();


}










void Arduino::writeChar(char c){
    arduino->write(&c,1);
    arduino->waitForBytesWritten();

}

void Arduino::close(void){
    arduino->close();
}
