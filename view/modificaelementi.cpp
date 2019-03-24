#include "modificaelementi.h"

modificaelementi::modificaelementi(ContenutoMultimediale* m, QWidget* parent) : QWidget(parent) , multimedia(m) {
    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);

    layout = new QVBoxLayout(this);

    //Creazione del titolo della pagina
    QLabel* titoloFinestra = new QLabel(this);
    titoloFinestra->setText(tr("Modifica Contenuti"));
    titoloFinestra->setFont(QFont("Times", 36, QFont::Bold));
    titoloFinestra->setAlignment(Qt::AlignHCenter);
    titoloFinestra->setStyleSheet("QLabel {color : #cc0066; }");
    layout->addWidget(titoloFinestra);

    griglia = new QGridLayout;
    caricaCampiDaModificare();

    layout->addLayout(griglia);

//    grigliaModificaAvanzata = new QGridLayout;
 //   layout->addLayout(grigliaModificaAvanzata);

    //aggiunta del bottone di conferma e del bottone torna indietro

    QPushButton* confermaModifica = new QPushButton(this);
    confermaModifica->setText("Conferma la modifica");
    QPushButton* goBack = new QPushButton(this);
    goBack->setText("Torna alla schermata principale");

    QGridLayout* boxModifica = new QGridLayout;
    boxModifica->addWidget(confermaModifica,0,0, Qt::AlignCenter);
    boxModifica->addWidget(goBack,1,0, Qt::AlignCenter);
    boxModifica->setSizeConstraint(QLayout::SetMinimumSize);
    layout->addLayout(boxModifica);


    connect (goBack, SIGNAL(clicked()), parent, SLOT(mostraMainWindow()));

    this->setLayout(layout);

}

void modificaelementi::creaOpzione(QString etichetta, QString valoreCorrente, int lunghezza, QGridLayout* griglia, int riga) {
    QLabel* label = new QLabel(this);
    label->setText(etichetta);

    QLineEdit* box = new QLineEdit(this);
    box->setFixedWidth(lunghezza);
    box->setText(valoreCorrente);

    //vettoreOpzioni.push_back(box);
    griglia->addWidget(label, riga, 0, Qt::AlignLeft);
    griglia->addWidget(box, riga, 1, Qt::AlignLeft);
}


void modificaelementi::caricaCampiDaModificare() {
    creaOpzione("Titolo:", QString::fromStdString(multimedia->getTitolo()), 250, griglia, 1);
    creaOpzione("Durata:", QString::number(multimedia->getDurata()), 250, griglia, 2);
    creaOpzione("Genere:", QString::fromStdString(multimedia->getGenere()), 250, griglia, 3);
    creaOpzione("Dimensione:", "Inserisci la dimensione in MB", 250, griglia, 4);
    creaOpzione("Valutazione:", QString::number(multimedia->getValutazione()), 250, griglia, 5);
    creaOpzione("Autore:", QString::fromStdString(multimedia->getAutore()), 250, griglia, 6);
    creaOpzione("Anno di uscita:", "Inserisci l'anno", 250, griglia, 7);


    film* f = dynamic_cast<film*>(multimedia);
    if (f) {
        creaOpzione("Risoluzione:", "Inserisci la risoluzione", 250, griglia, 8);
        creaOpzione("Regista:", "Inserisci il regista", 250, griglia, 9);
        creaOpzione("Saga:", "Inserisci la saga", 250, griglia, 10);
    }
    episodio* e = dynamic_cast<episodio*>(multimedia);
    if (e) {
        creaOpzione("Risoluzione:", "Inserisci la risoluzione", 250, griglia, 8);
        creaOpzione("Serie:", "Inserisci la serie", 250, griglia, 9);
        creaOpzione("Canale:", "Inserisci il canale o servizio di streaming", 250, griglia, 10);
    }
    podcast* p = dynamic_cast<podcast*>(multimedia);
    if (p) {
        creaOpzione("Qualità:", "Inserisci la qualità", 250, griglia, 8);
        creaOpzione("Album:", "Inserisci l'album", 250, griglia, 9);
        creaOpzione("Produttore:", "Inserisci il produttore", 250, griglia, 10);
    }
    canzone* c = dynamic_cast<canzone*>(multimedia);
    if (c) {
        creaOpzione("Qualità:", "Inserisci la qualità", 250, griglia, 8);
        creaOpzione("Raccolta:", "Inserisci la raccolta", 250, griglia, 9);
        creaOpzione("Ospite:", "Inserisci l'ospite", 250, griglia, 10);
    }

}

