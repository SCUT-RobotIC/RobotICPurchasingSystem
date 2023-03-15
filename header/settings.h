
#ifndef SETTINGS_H
#define SETTINGS_H
#include<QString>
namespace settings{


struct SETTINGS_STRUCT{
    QString dataPath;
};

Q_GLOBAL_STATIC(SETTINGS_STRUCT, settings);
void getSettingsFromFile();
void updateSettingsToFile();



}



#endif // SETTINGS_H
