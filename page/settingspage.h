#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H


#include <QWidget>
#include"header/settings.h"
namespace Ui {
    class SettingsPage;
}

class SettingsPage : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsPage(QWidget *parent = nullptr);
    ~SettingsPage();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

public slots:

private:
    Ui::SettingsPage *ui;


signals:

};

#endif // SETTINGSPAGE_H
