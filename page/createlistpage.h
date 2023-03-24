#ifndef CREATELISTPAGE_H
#define CREATELISTPAGE_H

#include <QWidget>

namespace Ui {
class CreateListPage;
}

class CreateListPage : public QWidget
{
    Q_OBJECT

public:
    explicit CreateListPage(QWidget *parent = nullptr);
    ~CreateListPage();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::CreateListPage *ui;
};

#endif // CREATELISTPAGE_H
