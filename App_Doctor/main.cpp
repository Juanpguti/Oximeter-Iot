#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Create a QApplication object, which manages the application's event loop
    MainWindow w; // Create an instance of the MainWindow class
    w.show(); // Show the main window
    return a.exec(); // Start the event loop of the application
}
