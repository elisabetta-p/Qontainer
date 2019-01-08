#include "mainwindow.h"
#include "ricercaavanzata.h"
#include "aggiungi.h"
#include <QImage>
mainwindow::mainwindow(container<ContenutoMultimediale*>* p_contenitore, QWidget* parent ) : QWidget (parent), cont(p_contenitore) {

    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);

    layout = new QVBoxLayout(this);

    //Creazione del titolo Qontainer

    QLabel* titoloFinestra = new QLabel();
    titoloFinestra->setScaledContents(true);
    titoloFinestra->setBackgroundRole(QPalette::Dark);

    QPixmap logo("/home/studente/Desktop/ProgettoP2/view/logo1.png");
    titoloFinestra->setPixmap(logo);
    /*
    titoloFinestra->setMinimumSize(this->width(), 50);
    titoloFinestra->setText(tr("Qontainer"));
    titoloFinestra->setFont(QFont("Times", 36, QFont::Bold));
    titoloFinestra->setAlignment((Qt::AlignHCenter));
    titoloFinestra->setStyleSheet("QLabel {color : #cc0066; }");
    */

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
    cantanti->setText("Canzoni");
    QLabel* podcastLabel = new QLabel;
    podcastLabel->setText("Podcast");
    QLabel* serie = new QLabel;
    serie->setText("Serie");
    QLabel* filmLabel = new QLabel;
    filmLabel->setText("Film");



    griglia = new QGridLayout;
    griglia->addWidget(cantanti, 0, 0, Qt::AlignCenter);
    griglia->addWidget(podcastLabel, 0, 1, Qt::AlignCenter);
    griglia->addWidget(filmLabel, 0, 2, Qt::AlignCenter);
    griglia->addWidget(serie, 0, 3, Qt::AlignCenter);

    /* aggiunta delle varie scroll bar nei 4 layout verticali*/

    QTextBrowser* areaCantanti = new QTextBrowser;
    QTextBrowser* areaPodcast = new QTextBrowser;
    QTextBrowser* areaSerie = new QTextBrowser;
    QTextBrowser* areaFilm = new QTextBrowser;

    griglia->addWidget(areaCantanti, 1,0,Qt::AlignCenter);
    griglia->addWidget(areaPodcast, 1,1,Qt::AlignCenter);
    griglia->addWidget(areaFilm, 1,2,Qt::AlignCenter);
    griglia->addWidget(areaSerie, 1,3,Qt::AlignCenter);


    areaCantanti->setVerticalScrollBar(new QScrollBar());
    areaPodcast->setVerticalScrollBar(new QScrollBar());
    areaSerie->setVerticalScrollBar(new QScrollBar());
    areaFilm->setVerticalScrollBar(new QScrollBar());



    //caricamento della musica
    for (auto it=(*cont).begin(); it!=(*cont).end(); ++it) {
        if (dynamic_cast<canzone*>((*cont)[it])){
            QString titolo = QString::fromStdString((*cont)[it]->getTitolo());
            areaCantanti->append(titolo);
        }
    }
    //caricamento dei podcast
    for (auto it=(*cont).begin(); it!=(*cont).end(); ++it) {
        if (dynamic_cast<podcast*>((*cont)[it])){
            QString titolo = QString::fromStdString((*cont)[it]->getTitolo());
            areaPodcast->append(titolo);
        }
    }
    //caricamento dei film
    for (auto it=(*cont).begin(); it!= (*cont).end();++it) {
        if (dynamic_cast<film*>((*cont)[it])){
            QString titolo = QString::fromStdString((*cont)[it]->getTitolo());
            areaFilm->append(titolo);
        }
    }
    //caricamento degli episodi
    for (auto it=(*cont).begin(); it!= (*cont).end();++it) {
        if (dynamic_cast<episodio*>((*cont)[it])){
            QString titolo = QString::fromStdString((*cont)[it]->getTitolo());
            areaSerie->append(titolo);
        }
    }

    layout->addLayout(griglia);

    //aggiunta dei due bottoni per la ricerca e per l'aggiunta di contenuto

    connect (ricerca, SIGNAL(clicked()), parent, SLOT(mostraRicerca()));
    connect (aggiungi, SIGNAL(clicked()), parent, SLOT(mostraAggiungi()));

    this->setLayout(layout);

}
