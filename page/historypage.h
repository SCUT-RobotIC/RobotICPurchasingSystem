#ifndef HISTORYPAGE_H
#define HISTORYPAGE_H

#include <QWidget>
#include <QStringList>
namespace Ui {
class HistoryPage;
}

class HistoryPage : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryPage(QWidget *parent = nullptr);
    ~HistoryPage();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::HistoryPage *ui;
    QStringList fileList;
    void updateTable(QString filename);
};

#endif // HISTORYPAGE_H
