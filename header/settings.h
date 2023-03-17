
#ifndef SETTINGS_H
#define SETTINGS_H
#include<QString>
namespace settings{


struct SETTINGS_STRUCT{
   static QString dataPath;
};


void getSettingsFromFile();
void updateSettingsToFile();



}



#endif // SETTINGS_H
