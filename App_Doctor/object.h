#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>

class Object : public QObject
{
    Q_OBJECT
public:
    explicit Object(QObject *parent = nullptr);

signals:

};

#endif // OBJECT_H