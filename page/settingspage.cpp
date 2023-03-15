#include "settingspage.h"
#include "ui_settingspage.h"
#include "header/jsonoperation.h"
#include "header/settings.h"
#include <QJsonObject>
#include <QFileDialog>

SettingsPage::SettingsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsPage)
{
    ui->setupUi(this);

    ui->lineEdit->setText(settings::settings->dataPath);

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
    settings::settings->dataPath = QFileDialog::getExistingDirectory(this, "选择数据库路径", settings::settings->dataPath, QFileDialog::ShowDirsOnly);
    ui->lineEdit->setText(settings::settings->dataPath);

}



