#include "historypage.h"
#include "ui_historypage.h"

HistoryPage::HistoryPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryPage)
{
    ui->setupUi(this);
}

HistoryPage::~HistoryPage()
{
    delete ui;
}
