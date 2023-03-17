#include"header/settings.h"
#include"header/jsonoperation.h"
#include<QApplication>

namespace settings{


//Q_GLOBAL_STATIC(QString, dataPath);
QString SETTINGS_STRUCT::dataPath="";
void getSettingsFromFile()
{
    bool success=false;
    QJsonObject inputsettings=JsonOperation::readJson(QApplication::applicationDirPath()+"/settings.json",success);
    SETTINGS_STRUCT::dataPath=inputsettings.value("directory").toString();

}
void updateSettingsToFile()
{


}

}


