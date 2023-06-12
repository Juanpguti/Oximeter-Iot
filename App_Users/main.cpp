#include "mainwindow.h" // Include the header file for the MainWindow class

#include <QApplication> // Include the QApplication header

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Create a QApplication instance

    MainWindow w; // Create an instance of the MainWindow class
    w.show(); // Show the main window

    return a.exec(); // Start the event loop and execute the application
}
