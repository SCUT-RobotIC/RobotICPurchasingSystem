#include "historypage.h"
#include "ui_historypage.h"
#include "header/settings.h"
#include "header/jsonoperation.h"
#include <QDir>
#include<QDebug>
#include<QJsonArray>

HistoryPage::HistoryPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryPage)
{
    ui->setupUi(this);
    ui->tableWidget->setSortingEnabled(true);

    //获取文件列表
    QDir jsonDir(settings::SETTINGS_STRUCT::dataPath+"/json/");
    QFileInfoList jsonList= jsonDir.entryInfoList();
    if(!jsonList.isEmpty())
    {
        foreach(QFileInfo fileinfo, jsonList)
        {
            QString filter = fileinfo.suffix();
            filter = fileinfo.suffix();    //后缀名
            if(filter != "json" )
            {
                continue;
            }
            fileList.append(fileinfo.baseName());
            ui->comboBox->addItem(fileinfo.baseName());
        }
    }
    ui->comboBox->setCurrentIndex(ui->comboBox->count()-1);
    //打开最后一个文件


}

HistoryPage::~HistoryPage()
{
    delete ui;
}

void HistoryPage::updateTable(QString filename)
{
    //清空内容
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->clearContents();
    //更新文档
    bool success=false;
    settings::getSettingsFromFile();
    //qDebug()<<settings::SETTINGS_STRUCT::dataPath;
    QJsonObject rootObj = JsonOperation::readJson(settings::SETTINGS_STRUCT::dataPath+"/json/"+filename,success);
    if (success==false)
    {
        JsonOperation::createJsonFile(settings::SETTINGS_STRUCT::dataPath+"/json/",filename);
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
    ui->pushButton_2->setEnabled(false);

}



void HistoryPage::on_comboBox_currentIndexChanged(int index)
{
    updateTable(ui->comboBox->currentText()+".json");

}

