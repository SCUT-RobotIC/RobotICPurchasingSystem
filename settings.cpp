#include"header/settings.h"
#include"header/jsonoperation.h"
#include<QApplication>

namespace settings{


void getSettingsFromFile()
{
    bool success=false;
    QJsonObject inputsettings=JsonOperation::readJson(QApplication::applicationDirPath()+"/settings.json",success);
    settings->dataPath=inputsettings.value("directory").toString();
}
void updateSettingsToFile()
{


}

}


