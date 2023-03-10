#ifndef EXCELOPERATION_H
#define EXCELOPERATION_H
#include<QFile>

class ExcelOperation
{
public:
    ExcelOperation();
    bool static saveExcelFromJson(QFile *jsonfile);
    bool static createExcel(const QString &filepath,const QString &filename);
};

#endif // EXCELOPERATION_H
