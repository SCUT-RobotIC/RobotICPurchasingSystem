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

private:
    Ui::HistoryPage *ui;
    QStringList fileList;
};

#endif // HISTORYPAGE_H
