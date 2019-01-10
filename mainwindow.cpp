#include "mainwindow.h"

mainwindow::mainwindow(QWidget* parent ) : QMainWindow (parent) {
    setWindowTitle("Qontainer - Elisabetta Piombin");
    setFixedSize(700,650);
    setFocusPolicy(Qt::StrongFocus);

     //Creazione del titolo Qontainer
    QGroupBox* titoloGropuBox = new QGroupBox(this);

    QLabel* titolo = new QLabel(this);
    titolo->setMinimumSize(this->width(), 100);
    titolo->setText(tr("Qontainer"));
    titolo->setFont(QFont("Times", 36, QFont::Bold));

    QHBoxLayout* boxTitolo = new QHBoxLayout;

    boxTitolo->addWidget(titolo);

    boxTitolo->setSizeConstraint(QLayout::SetMinimumSize);
    titoloGropuBox->setLayout(boxTitolo);
    titolo->setAlignment(Qt::AlignCenter);

    //aggiunta dei due bottoni per la ricerca e per l'aggiunta di contenuto
    QGroupBox* gruppoBottoni = new QGroupBox(this);

    QPushButton* ricerca = new QPushButton(this);
    ricerca->setText("Ricerca Avanzata");
    QPushButton* aggiungi = new QPushButton(this);
    aggiungi->setText("Aggiungi contenuto");


    QHBoxLayout* boxBottoni = new QHBoxLayout;

    boxBottoni->addWidget(ricerca);
    boxBottoni->addWidget(aggiungi);

    boxBottoni->setSizeConstraint(QLayout::SetMinimumSize);
    gruppoBottoni->setLayout(boxBottoni);
    gruppoBottoni->setGeometry(0, titolo->height()+26, this->width(), 0);
    //gruppoBottoni->setMinimumSize(QSize(this->width(),100));

    //etichetta "la tua libreria"
    QLabel* lib = new QLabel(this);
    lib->setText(tr("La tua libreria:"));
    lib->setMinimumSize(QSize(this->width(), 400));
    lib->setFont(QFont("Times", 24));

    //creazione della griglia: nomi
    QGroupBox* nomi = new QGroupBox(this);
    QLabel* cantanti = new QLabel(this);
    cantanti->setText("Cantanti");
    QLabel* podcast = new QLabel(this);
    podcast->setText("Podcast");
    QLabel* serie = new QLabel(this);
    serie->setText("Serie");
    QLabel* film = new QLabel(this);
    film->setText("Film");

    QHBoxLayout* layoutNomi = new QHBoxLayout;
    layoutNomi->addWidget(cantanti);
    layoutNomi->addWidget(podcast);
    layoutNomi->addWidget(serie);
    layoutNomi->addWidget(film);

    layoutNomi->setSizeConstraint(QLayout::SetMinimumSize);
    nomi->setLayout(layoutNomi);
    nomi->setMinimumSize(QSize(this->width(), 500));

    //creazione della griglia: elenco dei file?????? how

}

