#include "header/jsonoperation.h"
#include<QFile>
#include<QJsonParseError>
#include<QJsonDocument>
#include<QJsonArray>
#include<QCoreApplication>
#include<QDir>

JsonOperation::JsonOperation()
{

}

QJsonObject JsonOperation::readJson(QString fileurl,bool &success)
{
    QFile file(fileurl);
    QJsonObject rootObj;
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        success=false;
        return rootObj;
    }

    QByteArray array = file.readAll();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(array,&jsonError);

    if(jsonError.error == QJsonParseError::NoError)
    {
       rootObj=jsonDoc.object();
       success=true;
       return rootObj;
    }
    success=false;
    return rootObj;
}


bool JsonOperation::writeJsonFromWidget(QString fileurl,QTableWidget *widget)
{
//    widget->row();
//    widget->column();
    QJsonObject rootObject;
    QJsonArray jsonArray;
    int n=widget->rowCount();
    for(int i=0;i<n;i++)
    {
        //QJsonObject item("",widget->cellWidget(i,0));
        QJsonObject item;
        item.insert("name",widget->item(i,0)->text());
        item.insert("type",widget->item(i,1)->text());
        item.insert("number",widget->item(i,2)->text());
        item.insert("link",widget->item(i,3)->text());
        item.insert("name",widget->item(i,4)->text());
        item.insert("purchaser",widget->item(i,5)->text());
        item.insert("state",widget->item(i,6)->text());
        item.insert("invoice",widget->item(i,7)->text());
        item.insert("notes",widget->item(i,8)->text());
        jsonArray.append(item);
    }
    QJsonDocument doc;
    doc.setObject(rootObject);
    if(!QFile::exists(fileurl))
    {
        createJsonFile();
    }
    QFile file(fileurl);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    stream << doc.toJson();
    file.close();
    return true;
}


bool JsonOperation::createJsonFile(const QString &filepath,const QString &filename)
{
    //文件是否存在
    if(QFile::exists(filepath+"/"+filename))
        return true;//文件存在，则确认可以操作
    //文件不存在，先看路径是否存在
    QDir dir(filepath);
    if(!dir.exists(filepath))
    {
        //路径不存在，则创建路径
        if(!dir.mkdir(filepath))
            return false;//路径创建失败就没办法了，通常不会失败
    }
    //到这里需确认路径已经ok，且文件不存在，创建文件
    QFile file(filepath+"/"+filename);
    //当以Write方式打开时，若文件不存在则自动创建
    if(!file.open(QIODevice::WriteOnly))
        return false;
    file.close();
    return true;
}

