#include "mainwindow.h"
#include "ricercaavanzata.h"
#include "aggiungi.h"

mainwindow::mainwindow(QWidget* parent ) : QWidget (parent) {
    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);

    layout = new QVBoxLayout(this);

     //Creazione del titolo Qontainer
    //QGroupBox* titoloGropuBox = new QGroupBox(this);

    QLabel* titoloFinestra = new QLabel(this);
    titoloFinestra->setMinimumSize(this->width(), 50);
    titoloFinestra->setText(tr("Qontainer"));
    titoloFinestra->setFont(QFont("Times", 36, QFont::Bold));
    titoloFinestra->setAlignment((Qt::AlignHCenter));
    titoloFinestra->setStyleSheet("QLabel {color : #cc0066; }");

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
    QLabel* filmLabel = new QLabel;
    filmLabel->setText("Film");



    griglia = new QGridLayout;
    griglia->addWidget(cantanti, 0, 0, Qt::AlignCenter);
    griglia->addWidget(podcast, 0, 1, Qt::AlignCenter);
    griglia->addWidget(filmLabel, 0, 2, Qt::AlignCenter);
    griglia->addWidget(serie, 0, 3, Qt::AlignCenter);

    listaCantanti = new QVBoxLayout(this);
    listaPodcast = new QVBoxLayout(this);
    listaSerie = new QVBoxLayout(this);
    listaFilm = new QVBoxLayout(this);







    /* aggiunta delle varie scroll bar nei 4 layout verticali*/
    /*
    QScrollArea* scrollAreaCantanti = new QScrollArea;
    QScrollArea* scrollAreaPodcast = new QScrollArea;
    QScrollArea* scrollAreaSerie = new QScrollArea;
    QScrollArea* scrollAreaFilm = new QScrollArea;
    //scrollAreaCantanti->setBackgroundRole(QPalette::Light);
    scrollAreaCantanti->setLayout(listaCantanti);
    scrollAreaPodcast->setLayout(listaPodcast);
    scrollAreaSerie->setLayout(listaSerie);
    scrollAreaFilm->setLayout(listaFilm);

    griglia->addWidget(scrollAreaCantanti, 1, 0, Qt::AlignCenter);
    griglia->addWidget(scrollAreaPodcast, 1, 1, Qt::AlignCenter);
    griglia->addWidget(scrollAreaSerie, 1, 3, Qt::AlignCenter);
    griglia->addWidget(scrollAreaFilm, 1, 2, Qt::AlignCenter);
*/
    QTextBrowser* areaCantanti = new QTextBrowser;
    QTextBrowser* areaPodcast = new QTextBrowser;
    QTextBrowser* areaSerie = new QTextBrowser;
    QTextBrowser* areaFilm = new QTextBrowser;
/*
    areaCantanti->setLayout(listaCantanti);
    areaPodcast->setLayout(listaPodcast);
    areaSerie->setLayout(listaSerie);
    areaFilm->setLayout(listaFilm);
*/
    griglia->addWidget(areaCantanti, 1,0,Qt::AlignCenter);
    griglia->addWidget(areaPodcast, 1,1,Qt::AlignCenter);
    griglia->addWidget(areaFilm, 1,2,Qt::AlignCenter);
    griglia->addWidget(areaSerie, 1,3,Qt::AlignCenter);


    areaCantanti->setVerticalScrollBar(new QScrollBar());
    areaPodcast->setVerticalScrollBar(new QScrollBar());
    areaSerie->setVerticalScrollBar(new QScrollBar());
    areaFilm->setVerticalScrollBar(new QScrollBar());

    layout->addLayout(griglia);

    /*
    CICLO CHE CARICA I CONTENUTI DA FILE DENTRO LE VARIE LISTE VERTICALMENTE
    */

    //aggiunta dei due bottoni per la ricerca e per l'aggiunta di contenuto

    connect (ricerca, SIGNAL(clicked()), parent, SLOT(mostraRicerca()));
    connect (aggiungi, SIGNAL(clicked()), parent, SLOT(mostraAggiungi()));

    this->setLayout(layout);

    //metto cose nel contenitore
    ContenutoMultimediale* f1 = new film ("iron man", 126, "azione",1500.0,5,"Marvel", 2012,1080,"Joss Whedon","MCU");
    ContenutoMultimediale* f2 = new film ("iron man 3", 127, "azione", 4585.5, 9, "Marvel", 1013, 1080, "Tizio", "MCU");
    ContenutoMultimediale* c1 = new canzone ("Organs",3, "Indie", 3.5,8,"Of Monsters and Men", 2016, 125, "Beneath the skin", "nd");
    contenitore.insert(f1);
    contenitore.insert(f2);
    contenitore.insert(c1);


    caricaFilm();
}


void mainwindow::caricaFilm() {
    for (auto it = contenitore.begin(); it != contenitore.end(); ++it) {
        if (dynamic_cast<film*>(contenitore[it])) {
            areaFilm->append(QString("banana"));
        }
    }
}

