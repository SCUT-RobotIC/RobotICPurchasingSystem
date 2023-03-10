#include "page/mainwindow.h"

#include <QApplication>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //重复启动检测
    QString path = QCoreApplication::applicationDirPath()+"/app.lock";
    QLockFile lockFile(path);
    if (!lockFile.tryLock(100))
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("应用程序已经在运行！");
        msgBox.exec();
    qApp->exit();
    return a.exec();
    }

    w.show();
    return a.exec();
}
