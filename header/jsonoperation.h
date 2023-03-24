#ifndef FILEIO_H
#define FILEIO_H

#include<QString>
#include<QJsonObject>
#include<QTableWidget>
class JsonOperation
{
public:
    JsonOperation();
    static QJsonObject readJson(QString fileurl,bool &success);
    static bool writeJsonFromWidget(const QString &fileurl,QTableWidget *widget);
    static bool writeJsonFromWidget(const QString &filepath,const QString &filename,QTableWidget *widget);
    static bool createJsonFile(const QString &filepath,const QString &filename);
private:

};

#endif // FILEIO_H
