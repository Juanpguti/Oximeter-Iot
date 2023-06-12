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

    void on_tab_5_customContextMenuRequested(const QPoint &pos);

    void on_tab_5_windowIconTextChanged(const QString &iconText);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void timerfin();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
   };
#endif // MAINWINDOW_H
