#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <arduino.h>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QVariantMap>
#include <QUrlQuery>

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

    void on_tab_5_customContextMenuRequested(const QPoint &pos); // Slot for custom context menu request

    void on_tab_5_windowIconTextChanged(const QString &iconText); // Slot for window icon text change

    void on_pushButton_3_clicked(); // Slot for the click event of pushButton_3

    void on_pushButton_4_clicked(); // Slot for the click event of pushButton_4

    void on_pushButton_5_clicked(); // Slot for the click event of pushButton_5

    void on_pushButton_6_clicked(); // Slot for the click event of pushButton_6

    void timerfin(); // Slot for the timer timeout event

    void on_tabWidget_currentChanged(int index); // Slot for tab widget index change event

private:
    Ui::MainWindow *ui; // Pointer to the UI object
    QTimer *timer; // Pointer to the QTimer object
   };
#endif // MAINWINDOW_H
