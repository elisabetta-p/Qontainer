#include "mainwindow.h"
#include "ricercaavanzata.h"
#include "aggiungi.h"

mainwindow::mainwindow(QWidget* parent ) : QWidget (parent) {

    setWindowTitle("Qontainer - Elisabetta Piombin");
    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);

    layout = new QVBoxLayout(this);

     //Creazione del titolo Qontainer
    //QGroupBox* titoloGropuBox = new QGroupBox(this);

    QLabel* titoloFinestra = new QLabel(this);
    titoloFinestra->setMinimumSize(this->width(), 50);
    titoloFinestra->setText(tr("Qontainer"));
    titoloFinestra->setFont(QFont("Times", 26, QFont::Bold));
    titoloFinestra->setAlignment((Qt::AlignHCenter));

    layout->addWidget(titoloFinestra);


    QHBoxLayout* boxBottoni = new QHBoxLayout;
    QPushButton* ricerca = new QPushButton(this);
    ricerca->setText("Ricerca Avanzata");
    QPushButton* aggiungi = new QPushButton(this);
    aggiungi->setText("Aggiungi contenuto");

    boxBottoni->addWidget(ricerca);
    boxBottoni->addWidget(aggiungi);

    layout->addLayout(boxBottoni);

    //boxTitolo->setSizeConstraint(QLayout::SetMinimumSize);
    //titoloGropuBox->setLayout(boxTitolo);
    //titolo->setAlignment(Qt::AlignCenter);



    //etichetta "la tua libreria"
    QLabel* lib = new QLabel;
    lib->setMargin(10);
    lib->setText(tr("La tua libreria:"));
    lib->setFont(QFont("Times", 24));
    layout->addWidget(lib);


    //creazione della griglia:
    //quattro QLabel, per i titoli, e poi quattro QListBox per la lista di elementi
    //che verranno inseriti

    //QGroupBox* boxListe = new QGroupBox(this);
    QLabel* cantanti = new QLabel;
    cantanti->setText("Cantanti");
    QLabel* podcast = new QLabel;
    podcast->setText("Podcast");
    QLabel* serie = new QLabel;
    serie->setText("Serie");
    QLabel* film = new QLabel;
    film->setText("Film");



    griglia = new QGridLayout;
    griglia->addWidget(cantanti, 0, 0, Qt::AlignCenter);
    griglia->addWidget(podcast, 0, 1, Qt::AlignCenter);
    griglia->addWidget(film, 0, 2, Qt::AlignCenter);
    griglia->addWidget(serie, 0, 3, Qt::AlignCenter);

    QVBoxLayout* listaCantanti = new QVBoxLayout(this);
    QVBoxLayout* listaPodcast = new QVBoxLayout(this);
    QVBoxLayout* listaSerie = new QVBoxLayout(this);
    QVBoxLayout* listaFilm = new QVBoxLayout(this);

    griglia->addLayout(listaCantanti, 1, 0, Qt::AlignCenter);
    griglia->addLayout(listaPodcast, 1, 1, Qt::AlignCenter);
    griglia->addLayout(listaSerie, 1, 3, Qt::AlignCenter);
    griglia->addLayout(listaFilm, 1, 4, Qt::AlignCenter);


    layout->addLayout(griglia);



    /* aggiunta delle varie scroll bar nei 4 layout verticali*/

    QScrollArea* scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setLayout(listaCantanti);
    scrollArea->setLayout(listaPodcast);
    scrollArea->setLayout(listaSerie);
    scrollArea->setLayout(listaFilm);

    /*
    CICLO CHE CARICA I CONTENUTI DA FILE DENTRO LE VARIE LISTE VERTICALMENTE
    */

    //aggiunta dei due bottoni per la ricerca e per l'aggiunta di contenuto

    connect (ricerca, SIGNAL(clicked()), parent, SLOT(schiacciaRicerca()));
    connect (aggiungi, SIGNAL(clicked()), this, SLOT(schiacciaAggiungi()));

    this->setLayout(layout);

}

/*void mainwindow::schiacciaRicerca() {

    ricercaavanzata* newRicerca = new ricercaavanzata();
    layout->addWidget(newRicerca);

}
*/
void mainwindow::schiacciaAggiungi() {
    this -> hide();
    aggiungi* newAggiungi = new aggiungi();
    newAggiungi -> show();
}


