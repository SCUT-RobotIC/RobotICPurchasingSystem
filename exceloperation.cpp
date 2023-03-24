#include "header/exceloperation.h"
#include "xlsxdocument.h"
#include<QFile>
#include<QJsonObject>
#include<QJsonArray>
ExcelOperation::ExcelOperation()
{

}


bool ExcelOperation::saveExcelFromJson(const QJsonObject &jsonObj,const QString &filepath,const QString &filename)
{
    QXlsx::Document xlsx;
    QJsonArray JsonArray;
    if(jsonObj.contains("list"))
    {
        JsonArray =  jsonObj.value("list").toArray();
        if(!JsonArray.isEmpty())
        {
            int n=JsonArray.size();
            for(int i = 0; i<n;i++)
            {
                QJsonObject jsonItem=JsonArray[i].toObject();
                xlsx.write("A"+QString::number(n), jsonItem.value("name").toString());
                xlsx.write("B"+QString::number(n), jsonItem.value("type").toString());
                xlsx.write("C"+QString::number(n), jsonItem.value("link").toString());
                xlsx.write("D"+QString::number(n), jsonItem.value("purchaser").toString());
                xlsx.write("E"+QString::number(n), jsonItem.value("invoice").toString());
                xlsx.write("F"+QString::number(n), jsonItem.value("notes").toString());
            }
        }
    }
    xlsx.saveAs(filepath+"/"+filename);
    return true;
}
bool ExcelOperation::createExcel(const QString &filepath,const QString &filename)
{
    QXlsx::Document xlsx;
    xlsx.write("A1", "Hello Qt!");
    xlsx.saveAs(filepath+"/"+filename);
    return true;
}

void ExcelOperation::run()
{



}
