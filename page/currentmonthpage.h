#ifndef CURRENTMONTHPAGE_H
#define CURRENTMONTHPAGE_H

#include <QWidget>
#include <QMenu>

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

    void on_pushButton_3_clicked();

private:
    Ui::CurrentMonthPage *ui;
    bool haveChanged;
    void updateTable();
    void addListToTable(const QString &fileurl);
    void getTableContent();

signals:


};

#endif // CURRENTMONTHPAGE_H
