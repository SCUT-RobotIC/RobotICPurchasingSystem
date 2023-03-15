#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "page/currentmonthpage.h"
#include "page/settingspage.h"
#include <QMainWindow>
#include <QLockFile>



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
    CurrentMonthPage *mCurrentMonthPage;
    SettingsPage *mSettingsPage;
    void resizeEvent(QResizeEvent *event);



};
#endif // MAINWINDOW_H
