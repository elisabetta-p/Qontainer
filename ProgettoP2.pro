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
    model/contenutomultimediale.cpp \
    model/audio.cpp \
    model/video.cpp \
    model/film.cpp \
    model/episodio.cpp \
    model/canzone.cpp \
    model/podcast.cpp \
    model/database.cpp \
    view/mainwindow.cpp \
    view/ricercaavanzata.cpp \
    view/aggiungi.cpp \
    view/qontainer.cpp \
    view/risultatoricerca.cpp \
    view/risultatoaggiunta.cpp \
    view/risultatoeliminazione.cpp \
    view/modificaelementi.cpp \
    view/risultatomodifica.cpp

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
    model/container.h \
    model/contenutomultimediale.h \
    model/audio.h \
    model/video.h \
    model/film.h \
    model/episodio.h \
    model/canzone.h \
    model/podcast.h \
    model/database.h \
    view/mainwindow.h \
    view/ricercaavanzata.h \
    view/aggiungi.h \
    view/qontainer.h \
    view/risultatoricerca.h \
    view/risultatoaggiunta.h \
    view/risultatoeliminazione.h \
    view/modificaelementi.h \
    view/risultatomodifica.h




