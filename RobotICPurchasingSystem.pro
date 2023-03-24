QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(QtXlsxWriter/src/xlsx/qtxlsx.pri)
CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS_RELEASE += -O3       # Release -O3

SOURCES += \
    exceloperation.cpp \
    jsonoperation.cpp \
    main.cpp \
    page/currentmonthpage.cpp \
    page/historypage.cpp \
    page/mainwindow.cpp \
    page/settingspage.cpp \
    settings.cpp

HEADERS += \
    header/exceloperation.h \
    header/jsonoperation.h \
    header/settings.h \
    page/currentmonthpage.h \
    page/historypage.h \
    page/mainwindow.h \
    page/settingspage.h

FORMS += \
    page/currentmonthpage.ui \
    page/historypage.ui \
    page/mainwindow.ui \
    page/settingspage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
