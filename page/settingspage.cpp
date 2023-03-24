#include "settingspage.h"
#include "ui_settingspage.h"
#include "header/jsonoperation.h"
#include "header/exceloperation.h"
#include "header/settings.h"
#include <QJsonObject>
#include <QFileDialog>


SettingsPage::SettingsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsPage)
{
    ui->setupUi(this);

    ui->lineEdit->setText(settings::SETTINGS_STRUCT::dataPath);

}
SettingsPage::~SettingsPage()
{
    delete ui;
}

void SettingsPage::on_pushButton_clicked()
{
    bool success=false;
    QJsonObject settings=JsonOperation::readJson(QApplication::applicationDirPath()+"/settings.json",success);
    //qDebug()<<QApplication::applicationDirPath()+"/settings.json"<<success;
    settings::SETTINGS_STRUCT::dataPath = QFileDialog::getExistingDirectory(this, "选择数据库路径", settings::SETTINGS_STRUCT::dataPath, QFileDialog::ShowDirsOnly);
    ui->lineEdit->setText(settings::SETTINGS_STRUCT::dataPath);
}




void SettingsPage::on_pushButton_2_clicked()
{
    bool success=false;
    QJsonObject arg=JsonOperation::readJson("E:/Programming/Qt/RobotICPurchasingSystem/RICPSData/json/2023-01.json",success);
    ExcelOperation::saveExcelFromJson(arg,"E:/Programming/Qt/RobotICPurchasingSystem/RICPSData/json","2023-01.xlsx");
}

