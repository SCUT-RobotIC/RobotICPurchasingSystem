#include "header/exceloperation.h"
#include "xlsxdocument.h"

#include<QThread>
ExcelOperation::ExcelOperation()
{

}


bool ExcelOperation::saveExcelFromJson(QFile *jsonfile)
{

}
bool ExcelOperation::createExcel(const QString &filepath,const QString &filename)
{
    QXlsx::Document xlsx;
    xlsx.write("A1", "Hello Qt!");
    xlsx.saveAs(filepath+"/"+filename);
}
