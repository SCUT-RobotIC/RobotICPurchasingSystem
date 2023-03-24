#include "excelpage.h"
#include "ui_excelpage.h"
#include "header/settings.h"
#include "header/jsonoperation.h"
#include "header/exceloperation.h"
#include<QDir>
#include<QFileDialog>

ExcelPage::ExcelPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExcelPage)
{
    ui->setupUi(this);
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
}

ExcelPage::~ExcelPage()
{
    delete ui;
}

void ExcelPage::on_pushButton_clicked()
{
    bool success=false;
    QString savepath=QFileDialog::getExistingDirectory(this, "选择数据库路径", settings::SETTINGS_STRUCT::dataPath, QFileDialog::ShowDirsOnly);
    QJsonObject arg=JsonOperation::readJson(settings::SETTINGS_STRUCT::dataPath+"/json/"+ui->comboBox->currentText()+".json",success);
    ExcelOperation::saveExcelFromJson(arg,savepath,ui->comboBox->currentText()+".xlsx");
}

