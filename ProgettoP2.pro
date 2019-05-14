QT += core
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
CONFIG+=sdk_no_version_check
QT += widgets
QT += gui
QT += core

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += model/audio.h \
           model/canzone.h \
           model/container.h \
           model/contenutomultimediale.h \
           model/database.h \
           model/episodio.h \
           model/film.h \
           model/podcast.h \
           model/video.h \
           view/aggiungi.h \
           view/mainwindow.h \
           view/modificaelementi.h \
           view/qontainer.h \
           view/ricercaavanzata.h \
           view/risultatoaggiunta.h \
           view/risultatoeliminazione.h \
           view/risultatomodifica.h \
           view/risultatoricerca.h \
           view/visualizzaelementi.h
SOURCES += main.cpp \
           model/audio.cpp \
           model/canzone.cpp \
           model/contenutomultimediale.cpp \
           model/database.cpp \
           model/episodio.cpp \
           model/film.cpp \
           model/podcast.cpp \
           model/video.cpp \
           view/aggiungi.cpp \
           view/mainwindow.cpp \
           view/modificaelementi.cpp \
           view/qontainer.cpp \
           view/ricercaavanzata.cpp \
           view/risultatoaggiunta.cpp \
           view/risultatoeliminazione.cpp \
           view/risultatomodifica.cpp \
           view/risultatoricerca.cpp \
           view/visualizzaelementi.cpp
RESOURCES += qml.qrc

DISTFILES +=
