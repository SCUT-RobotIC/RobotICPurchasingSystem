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
            xlsx.write("A1","名称" );
            xlsx.write("B1","类别" );
            xlsx.write("C1","数量" );
            xlsx.write("D1","链接" );
            xlsx.write("E1","购买人" );
            xlsx.write("F1","状态" );
            xlsx.write("G1","发票" );
            xlsx.write("H1","备注" );
            int n=JsonArray.size();
            for(int i = 0; i<n;i++)
            {
                QJsonObject jsonItem=JsonArray[i].toObject();
                xlsx.write("A"+QString::number(i+2), jsonItem.value("name").toString());
                xlsx.write("B"+QString::number(i+2), jsonItem.value("type").toString());
                xlsx.write("C"+QString::number(i+2), jsonItem.value("number").toString());
                xlsx.write("D"+QString::number(i+2), jsonItem.value("link").toString());
                xlsx.write("E"+QString::number(i+2), jsonItem.value("purchaser").toString());
                xlsx.write("F"+QString::number(i+2), jsonItem.value("state").toString());
                xlsx.write("G"+QString::number(i+2), jsonItem.value("invoice").toString());
                xlsx.write("H"+QString::number(i+2), jsonItem.value("notes").toString());
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
