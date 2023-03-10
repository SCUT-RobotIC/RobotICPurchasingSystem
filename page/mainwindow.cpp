#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"header/jsonoperation.h"
#include"header/exceloperation.h"


#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QTextStream>
#include<QFile>
#include<QDir>
#include<QLockFile>
#include<QMessageBox>
#include<QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CurrentMonth=new CurrentMonthPage(ui->tab);
    Settings=new SettingsPage(ui->tab_5);
    mDataPath=QApplication::applicationDirPath();

    QTimer::singleShot(100,this, [=]() {
        int width=ui->tabWidget->width(),height=ui->tab->height();
        CurrentMonth->resize(width,height);
        Settings->resize(width,height);
    });//构造函数中无法获取正确的窗口大小，所以要延时处理

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    int width=ui->tab->width(),height=ui->tab->height();
    //tabpage1->setSizePolicy(QSizePolicy(width,height));
    CurrentMonth->resize(width,height);

}






