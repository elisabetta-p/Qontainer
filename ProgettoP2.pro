QT += core
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
CONFIG+=sdk_no_version_check
QT += widgets
QT += gui
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    contenutomultimediale.cpp \
    audio.cpp \
    video.cpp \
    film.cpp \
    episodio.cpp \
    canzone.cpp \
    podcast.cpp \
    database.cpp \
    mainwindow.cpp \
    ricercaavanzata.cpp \
    aggiungi.cpp \
    qontainer.cpp \
    risultatoricerca.cpp \
    risultatoaggiunta.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    container.h \
    contenutomultimediale.h \
    audio.h \
    video.h \
    film.h \
    episodio.h \
    canzone.h \
    podcast.h \
    database.h \
    mainwindow.h \
    ricercaavanzata.h \
    aggiungi.h \
    qontainer.h \
    risultatoricerca.h \
    risultatoaggiunta.h




