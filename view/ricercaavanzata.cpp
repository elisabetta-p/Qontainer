#include "ricercaavanzata.h"
#include "mainwindow.h"
#include "risultatoricerca.h"
#include <iostream>
#include "qontainer.h"
#include <qobjectdefs.h>

ricercaavanzata::ricercaavanzata(container<ContenutoMultimediale*>* p_contenitore, QWidget* parent) : QWidget(parent), cont(p_contenitore) {
    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);


    layout = new QVBoxLayout(this);

    //Creazione del titolo Ricerca Avanzata
   QLabel* titoloFinestra = new QLabel(this);
   titoloFinestra->setText(tr("Ricerca Avanzata"));
   titoloFinestra->setFont(QFont("Times", 36, QFont::Bold));
   titoloFinestra->setAlignment(Qt::AlignHCenter);
   titoloFinestra->setStyleSheet("QLabel {color : #cc0066; }");

   layout->addWidget(titoloFinestra);


   griglia = new QGridLayout;

   QLabel* menuTendina = new QLabel(this);
   menuTendina->setText("Scegli il tipo di file che vuoi cercare: ");
   griglia->addWidget(menuTendina, 0,0,Qt::AlignLeft);

   //menu a tendina che andrà a destra
   opzioni = new QComboBox;
   opzioni->insertItem(0, tr("Scegli:"));
   opzioni->insertItem(1, tr("Film"));
   opzioni->insertItem(2, tr("Episodio"));
   opzioni->insertItem(3, tr("Canzoni"));
   opzioni->insertItem(4, tr("Podcast"));

   griglia->addWidget(opzioni, 0, 1, Qt::AlignLeft);


    //Creazione dei vari campi e delle text box
   creaOpzione("Titolo:", "Inserisci il titolo", 250, griglia, 1);
   //creaOpzione("Durata:", "Inserisci la durata in minuti:", 250, griglia, 2);
   //creaOpzione("Genere:", "Inserisci il genere", 250, griglia, 3);
   //creaOpzione("Dimensione:", "Inserisci la dimensione in MB", 250, griglia, 4);
   //creaOpzione("Valutazione:", "Inserisci la valutazione, da 0 a 10", 250, griglia, 5);
   creaOpzione("Autore:", "Inserisci l'autore", 250, griglia, 6);
   creaOpzione("Anno di uscita:", "Inserisci l'anno", 250, griglia, 7);

   //connect(opzioni, SIGNAL(activated(int)), this, SLOT(aggiungiInput(int)));

   layout->addLayout(griglia);


   grigliaRicercaAvanzata = new QGridLayout;
   layout->addLayout(grigliaRicercaAvanzata);

   QPushButton* cercaB = new QPushButton(this);
   cercaB->setText("Cerca");
   QPushButton* goBack = new QPushButton(this);
   goBack->setText("Torna alla schermata principale");


   QGridLayout* boxCerca = new QGridLayout;
   boxCerca->addWidget(cercaB,0,0, Qt::AlignCenter);
   boxCerca->addWidget(goBack,1,0, Qt::AlignCenter);

   boxCerca->setSizeConstraint(QLayout::SetMinimumSize);
   layout->addLayout(boxCerca);

   //connect (cercaB, SIGNAL(clicked()), parent, SLOT(mostraRisultato(string)));
   connect (goBack, SIGNAL(clicked()), parent, SLOT(mostraMainWindow()));

   this->setLayout(layout);

   connect(cercaB, SIGNAL(clicked()), this, SLOT(schiacciaRicerca()));
   connect(this, SIGNAL(invioRicerca(string,                                   
                                   string,
                                   unsigned short int)), parent, SLOT(mostraRisultato(string,
                                                                          string,
                                                                          unsigned short int
                                                                          )));
}

void ricercaavanzata::creaOpzione(QString etichetta, QString placeholder, int lunghezza, QGridLayout* griglia, int riga) {
    QLabel* label = new QLabel(this);
    label->setText(etichetta);

    QLineEdit* box = new QLineEdit(this);
    box->setFixedWidth(lunghezza);
    box->setPlaceholderText(placeholder);

    vettoreOpzioni.push_back(box);


    griglia->addWidget(label, riga, 0, Qt::AlignLeft);
    griglia->addWidget(box, riga, 1, Qt::AlignLeft);
}

void ricercaavanzata::schiacciaRicerca() {
    string titolo, genere, autore;
    double dim;
    unsigned short int durata, val, data;
    titolo = vettoreOpzioni[0]->text().toStdString();
    autore = vettoreOpzioni[1]->text().toStdString();
    data = vettoreOpzioni[2]->text().toUShort();
    emit invioRicerca(titolo, autore, data);
}
