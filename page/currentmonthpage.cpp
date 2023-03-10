#include "currentmonthpage.h"
#include "ui_currentmonthpage.h"
#include "header/jsonoperation.h"

#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QTextStream>
#include<QFile>
#include<QDir>
#include<QLockFile>
#include<QMessageBox>
#include<QTimer>
CurrentMonthPage::CurrentMonthPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CurrentMonthPage)
{
    ui->setupUi(this);
    ui->tableWidget->setSortingEnabled(true);
    updateTable();
}

CurrentMonthPage::~CurrentMonthPage()
{
    delete ui;
}

void CurrentMonthPage::updateTable()
{
   QString mDataPath=QApplication::applicationDirPath();


   QDateTime dateTime(QDateTime::currentDateTime());
   QString filename = dateTime.toString("yyyy-MM")+".json";
   bool success=false;
   QJsonObject rootObj = JsonOperation::readJson(mDataPath+"/"+filename,success);

   if (success==false)
   {
        JsonOperation::createJsonFile(mDataPath,filename);
   }

   QJsonArray JsonArray;
   if(rootObj.contains("list"))
   {
       JsonArray =  rootObj.value("list").toArray();
       if(!JsonArray.isEmpty())
       {
           int n=JsonArray.size();
           for(int i = 0; i<n;i++)
           {
               QJsonObject jsonItem=JsonArray[i].toObject();
               ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
               QTableWidgetItem *item = new QTableWidgetItem(jsonItem.value("name").toString());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, item); //添加到界面
               item = new QTableWidgetItem(jsonItem.value("type").toString());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, item); //添加到界面
               item = new QTableWidgetItem(QString::number(jsonItem.value("number").toInt()));
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, item); //添加到界面
               item = new QTableWidgetItem(jsonItem.value("link").toString());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, item); //添加到界面
               item = new QTableWidgetItem(jsonItem.value("purchaser").toString());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, item); //添加到界面
               item = new QTableWidgetItem(QString::number(jsonItem.value("state").toInt()));
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 5, item); //添加到界面
               item = new QTableWidgetItem(jsonItem.value("invoice").toString());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 6, item); //添加到界面
               item = new QTableWidgetItem(jsonItem.value("notes").toString());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 7, item); //添加到界面
           }
       }
   }
}

void CurrentMonthPage::getTableContent()
{
    QJsonObject rootObj;
    QJsonArray JsonArray;
    int n=ui->tableWidget->rowCount();
    for(int i=0;i<n;i++)
    {
        QJsonObject item;
        item.insert("name",ui->tableWidget->item(i,0)->text());
        item.insert("type",ui->tableWidget->item(i,1)->text());
        item.insert("number",ui->tableWidget->item(i,2)->text().toInt());
        item.insert("link",ui->tableWidget->item(i,3)->text());
        item.insert("purchaser",ui->tableWidget->item(i,4)->text());
        item.insert("state",ui->tableWidget->item(i,5)->text());
        item.insert("invoice",ui->tableWidget->item(i,6)->text());
        item.insert("notes",ui->tableWidget->item(i,7)->text());
        JsonArray.append(item);
    }
    rootObj.insert("list",JsonArray);


}

void CurrentMonthPage::on_addLine_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
}


void CurrentMonthPage::on_pushButton_2_clicked()
{
    QString mDataPath=QApplication::applicationDirPath();


    QDateTime dateTime(QDateTime::currentDateTime());
    QString filename = dateTime.toString("yyyy-MM")+".json";
    JsonOperation::writeJsonFromWidget(mDataPath+"/"+filename,ui->tableWidget);
}

