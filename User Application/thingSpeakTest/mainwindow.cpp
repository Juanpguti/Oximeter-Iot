#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user1.h"
#include <QJsonDocument>
#include <QJsonObject>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("D-Iotech");
    ui->tabWidget->setCurrentIndex(0);
    //manager = new QNetworkAccessManager(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tab_5_customContextMenuRequested(const QPoint &pos)
{

}

void MainWindow::on_tab_5_windowIconTextChanged(const QString &iconText)
{

}
//Usuario 1
void MainWindow::on_pushButton_3_clicked()
{
    User1 *u1;
    u1=new User1(this,1167232,"V5AQRWNPXTZZKFXU","3F9SQL68VM51F36Z");
    u1->show();
}

//Usuario 2
void MainWindow::on_pushButton_4_clicked()
{
    User1 *u1;
    u1=new User1(this,1226428,"UWGPMLIJKHCEGV4D","ZR6F5MGJ2U5CAT1A");
    u1->show();
}

//Usuario 3
void MainWindow::on_pushButton_5_clicked()
{
    User1 *u1;
    u1=new User1(this,1232035,"Y0W0XPCN7264ZYN1","DAAMAXYBSGLYAHKR");
    u1->show();
}

//Usuario 4
void MainWindow::on_pushButton_6_clicked()
{
    User1 *u1;
    u1=new User1(this,1232036,"SH18TLSOHNCWRUBI","G3THE8UDBOKWPE8I");
    u1->show();
}
