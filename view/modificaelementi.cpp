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

    vettoreModifiche.push_back(box);
    griglia->addWidget(label, riga, 0, Qt::AlignLeft);
    griglia->addWidget(box, riga, 1, Qt::AlignLeft);
}


void modificaelementi::caricaCampiDaModificare() {
    creaOpzione("Titolo:", QString::fromStdString(multimedia->getTitolo()), 250, griglia, 1);
    creaOpzione("Durata:", QString::number(multimedia->getDurata()), 250, griglia, 2);
    creaOpzione("Genere:", QString::fromStdString(multimedia->getGenere()), 250, griglia, 3);
    creaOpzione("Dimensione:", QString::number(multimedia->getDimensione()), 250, griglia, 4);
    creaOpzione("Valutazione:", QString::number(multimedia->getValutazione()), 250, griglia, 5);
    creaOpzione("Autore:", QString::fromStdString(multimedia->getAutore()), 250, griglia, 6);
    creaOpzione("Anno di uscita:", QString::number(multimedia->getDataUscita()), 250, griglia, 7);


    film* f = dynamic_cast<film*>(multimedia);
    if (f) {
        creaOpzione("Risoluzione:", QString::number(f->getRisoluzione()), 250, griglia, 8);
        creaOpzione("Regista:",  QString::fromStdString(f->getRegista()), 250, griglia, 9);
        creaOpzione("Saga:", QString::fromStdString(f->getSaga()), 250, griglia, 10);
    }
    episodio* e = dynamic_cast<episodio*>(multimedia);
    if (e) {
        creaOpzione("Risoluzione:", QString::number(e->getRisoluzione()), 250, griglia, 8);
        creaOpzione("Serie:", QString::fromStdString(e->getSerie()), 250, griglia, 9);
        creaOpzione("Canale:", QString::fromStdString(e->getCanale()), 250, griglia, 10);
    }
    podcast* p = dynamic_cast<podcast*>(multimedia);
    if (p) {
        creaOpzione("Qualità:", QString::number(p->getQualita()), 250, griglia, 8);
        creaOpzione("Raccolta:", QString::fromStdString(p->getRaccolta()), 250, griglia, 9);
        creaOpzione("Ospite:", QString::fromStdString(p->getOspite()), 250, griglia, 10);
    }
    canzone* c = dynamic_cast<canzone*>(multimedia);
    if (c) {
        creaOpzione("Qualità:", QString::number(c->getQualita()), 250, griglia, 8);
        creaOpzione("Album:", QString::fromStdString(c->getAlbum()), 250, griglia, 9);
        creaOpzione("Produttore:", QString::fromStdString(c->getProduttore()), 250, griglia, 10);
    }

}

