#ifndef CURRENTMONTHPAGE_H
#define CURRENTMONTHPAGE_H

#include <QWidget>
#include <QMenu>
#include <header/settings.h>
namespace Ui {
    class CurrentMonthPage;
}

class CurrentMonthPage : public QWidget
{
    Q_OBJECT

public:
    explicit CurrentMonthPage(QWidget *parent = nullptr);
    ~CurrentMonthPage();

private slots:
    void on_addLine_clicked();
    void on_deleteLine_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::CurrentMonthPage *ui;
    bool haveChanged;
    void updateTable();
    void getTableContent();

signals:
    settings::SETTINGS_STRUCT getSettings();


};

#endif // CURRENTMONTHPAGE_H
