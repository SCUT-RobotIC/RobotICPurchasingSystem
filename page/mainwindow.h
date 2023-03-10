#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLockFile>

#include "page/currentmonthpage.h"
#include "page/settingspage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


private:
    Ui::MainWindow *ui;
    QString mDataPath;
    CurrentMonthPage *CurrentMonth;
    SettingsPage *Settings;
    void resizeEvent(QResizeEvent *event);



};
#endif // MAINWINDOW_H
