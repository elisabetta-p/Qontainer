#include "modificaelementi.h"

modificaelementi::modificaelementi(container<ContenutoMultimediale*>* p_contenitore, int i, vector<ContenutoMultimediale*> v, QWidget* parent) : QWidget(parent), cont(p_contenitore), indice(i), vettRisultati(v) {
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

void modificaelementi::creaOpzione(QString etichetta, QString placeholder, int lunghezza, QGridLayout* griglia, int riga) {
    QLabel* label = new QLabel(this);
    label->setText(etichetta);

    QLineEdit* box = new QLineEdit(this);
    box->setFixedWidth(lunghezza);
    box->setPlaceholderText(placeholder);

    //vettoreOpzioni.push_back(box);
    griglia->addWidget(label, riga, 0, Qt::AlignLeft);
    griglia->addWidget(box, riga, 1, Qt::AlignLeft);
}


void modificaelementi::caricaCampiDaModificare() {
    creaOpzione("Titolo:", "Inserisci il titolo", 250, griglia, 1);
    creaOpzione("Durata:", "Inserisci la durata in minuti:", 250, griglia, 2);
    creaOpzione("Genere:", "Inserisci il genere", 250, griglia, 3);
    creaOpzione("Dimensione:", "Inserisci la dimensione in MB", 250, griglia, 4);
    creaOpzione("Valutazione:", "Inserisci la valutazione, da 0 a 10", 250, griglia, 5);
    creaOpzione("Autore:", "Inserisci l'autore", 250, griglia, 6);
    creaOpzione("Anno di uscita:", "Inserisci l'anno", 250, griglia, 7);

    /*
    ContenutoMultimediale* checkFilm = dynamic_cast<film*>(vettRisultati[indice]);
    if (checkFilm) {

    }
    ContenutoMultimediale* checkEp = dynamic_cast<episodio*>(vettRisultati[indice]);
    if (checkEp) {

    }
    ContenutoMultimediale* checkPod = dynamic_cast<podcast*>(vettRisultati[indice]);
    if (checkPod) {

    }
    ContenutoMultimediale* checkCanzone = dynamic_cast<canzone*>(vettRisultati[indice]);
    if (checkFilm) {

    }
    */
}

