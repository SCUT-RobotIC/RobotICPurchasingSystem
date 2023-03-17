#include "historypage.h"
#include "ui_historypage.h"
#include "header/settings.h"
#include <QDir>
#include<QDebug>
HistoryPage::HistoryPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryPage)
{
    ui->setupUi(this);
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

}

HistoryPage::~HistoryPage()
{
    delete ui;
}

void HistoryPage::on_comboBox_currentIndexChanged(int index)
{

}

