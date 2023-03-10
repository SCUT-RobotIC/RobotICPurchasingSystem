#ifndef CURRENTMONTHPAGE_H
#define CURRENTMONTHPAGE_H

#include <QWidget>

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

    void on_pushButton_2_clicked();

private:
    Ui::CurrentMonthPage *ui;
    void updateTable();
    void getTableContent();
};

#endif // CURRENTMONTHPAGE_H
