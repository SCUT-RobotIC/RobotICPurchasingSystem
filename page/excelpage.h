#ifndef EXCELPAGE_H
#define EXCELPAGE_H

#include <QWidget>

namespace Ui {
class ExcelPage;
}

class ExcelPage : public QWidget
{
    Q_OBJECT

public:
    explicit ExcelPage(QWidget *parent = nullptr);
    ~ExcelPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ExcelPage *ui;
    QStringList fileList;
};

#endif // EXCELPAGE_H
