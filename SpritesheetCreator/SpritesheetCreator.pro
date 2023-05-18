QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    imageprocessor.cpp \
    main.cpp \
    spritesheetcreator.cpp

HEADERS += \
    imageprocessor.h \
    spritesheetcreator.h

FORMS += \
    spritesheetcreator.ui


INCLUDEPATH += C:\opencv\build\include

LIBS += -LC:/opencv/build/install/x64/mingw/bin -lopencv_core460
LIBS += -LC:/opencv/build/install/x64/mingw/bin -lopencv_highgui460
LIBS += -LC:/opencv/build/install/x64/mingw/bin -lopencv_imgcodecs460
LIBS += -LC:/opencv/build/install/x64/mingw/bin -lopencv_features2d460


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
