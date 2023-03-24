#include "createlistpage.h"
#include "ui_createlistpage.h"
#include "header/jsonoperation.h"
#include<QFileDialog>
#include<QDebug>
CreateListPage::CreateListPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateListPage)
{
    ui->setupUi(this);
    ui->tableWidget->setSortingEnabled(true);
}

CreateListPage::~CreateListPage()
{
    delete ui;
}

void CreateListPage::on_pushButton_2_clicked()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->clearContents();
}


void CreateListPage::on_pushButton_clicked()
{

    QString savedir = QFileDialog::getSaveFileName(this,"选择保存路径",QDir::homePath()+"/documents/","*.json");
    JsonOperation::writeJsonFromWidget(savedir.left(savedir.lastIndexOf("/")),
                                       savedir.right(savedir.length()-savedir.lastIndexOf("/")-1),
                                       ui->tableWidget);
}

void CreateListPage::on_pushButton_3_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
}


void CreateListPage::on_pushButton_4_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

