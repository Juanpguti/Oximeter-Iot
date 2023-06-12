#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <arduino.h> // Include the Arduino header
#include <QMainWindow>
#include <QNetworkAccessManager> // Include the QNetworkAccessManager header
#include <QJsonDocument> // Include the QJsonDocument header
#include <QNetworkRequest> // Include the QNetworkRequest header
#include <QNetworkReply> // Include the QNetworkReply header
#include <QVariantMap> // Include the QVariantMap header
#include <QUrlQuery> // Include the QUrlQuery header

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enviar_clicked(); // Slot for the enviar button click

    void on_pushButton_clicked(); // Slot for the pushButton click

    void on_tab_5_customContextMenuRequested(const QPoint &pos); // Slot for the custom context menu request in tab_5

    void on_tab_5_windowIconTextChanged(const QString &iconText); // Slot for the window icon text change in tab_5

    void on_pushButton_3_clicked(); // Slot for the pushButton_3 click (Usuario 1)

    void on_pushButton_4_clicked(); // Slot for the pushButton_4 click (Usuario 2)

    void on_pushButton_5_clicked(); // Slot for the pushButton_5 click (Usuario 3)

    void on_pushButton_6_clicked(); // Slot for the pushButton_6 click (Usuario 4)

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
