#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFont>
#include <QButtonGroup>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QSize>
#include <QGridLayout>
#include <QScrollBar>
#include <QAction>
#include <QScrollArea>
#include <QTextBrowser>
#include "../model/container.h"
#include "../model/film.h"
#include "../model/episodio.h"
#include "../model/podcast.h"
#include "../model/canzone.h"

class mainwindow: public QWidget {
    Q_OBJECT
private:
    QPushButton* ricerca;
    QVBoxLayout* layout;
    QHBoxLayout* boxBottoni;
    QGridLayout* griglia;
    QVBoxLayout* listaCantanti, *listaPodcast, *listaSerie, *listaFilm;
    QTextBrowser* areaCantanti, *areaPodcast, *areaSerie, *areaFilm;
    container<ContenutoMultimediale*> contenitore;
public:
    mainwindow(QWidget* =nullptr);
    ~mainwindow() = default;
    void caricaFilm();
};

#endif // MAINWINDOW_H
