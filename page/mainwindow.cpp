#include "mainwindow.h"
#include "ui_mainwindow.h"



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
    mCurrentMonthPage=new CurrentMonthPage(ui->tab);
    mSettingsPage=new SettingsPage(ui->tab_5);
    mHistoryPage=new HistoryPage(ui->tab_4);





    QTimer::singleShot(100,this, [=]() {
        int width=ui->tabWidget->width(),height=ui->tab->height();
        mCurrentMonthPage->resize(width,height);
        mSettingsPage->resize(width,height);
        mHistoryPage->resize(width,height);
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
    mCurrentMonthPage->resize(width,height);

}







