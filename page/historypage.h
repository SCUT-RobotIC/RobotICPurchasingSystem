#ifndef HISTORYPAGE_H
#define HISTORYPAGE_H

#include <QWidget>

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
};

#endif // HISTORYPAGE_H
