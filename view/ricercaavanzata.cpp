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
   titoloFinestra->setStyleSheet("QLabel {color : #5a0c31; }");

   layout->addWidget(titoloFinestra);


   griglia = new QGridLayout;

    //Creazione dei vari campi e delle text box
   creaOpzione("Titolo:", "Inserisci il titolo", 250, griglia, 1);
   creaOpzione("Autore:", "Inserisci l'autore", 250, griglia, 6);
   creaOpzione("Anno di uscita:", "Inserisci l'anno", 250, griglia, 7);

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

   connect (goBack, SIGNAL(clicked()), parent, SLOT(mostraMainWindow()));
   connect(cercaB, SIGNAL(clicked()), this, SLOT(schiacciaRicerca()));
   connect(this, SIGNAL(invioRicerca(string,
                                   string,
                                   unsigned short int)), parent, SLOT(mostraRisultato(string,
                                                                          string,
                                                                          unsigned short int)));
   this->setLayout(layout);

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
    string titolo, autore;
    unsigned short int data;

    titolo = vettoreOpzioni[0]->text().toStdString();
    autore = vettoreOpzioni[1]->text().toStdString();
    data = vettoreOpzioni[2]->text().toUShort();
    emit invioRicerca(titolo, autore, data);
}
