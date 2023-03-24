#ifndef EXCELOPERATION_H
#define EXCELOPERATION_H
#include<QFile>
#include<QThread>
class ExcelOperation:public QThread
{
public:
    ExcelOperation();
    bool static saveExcelFromJson(const QJsonObject &jsonObj,const QString &filepath,const QString &filename);
    bool static createExcel(const QString &filepath,const QString &filename);
    void run()override;
};

#endif // EXCELOPERATION_H
