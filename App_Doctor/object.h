#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>

class Object : public QObject // Define the Object class that inherits from QObject
{
    Q_OBJECT // Enable the meta-object features of Qt
public:
    explicit Object(QObject *parent = nullptr); // Declare the constructor of Object class

signals: // Define the signals emitted by the Object class

};

#endif // OBJECT_H
