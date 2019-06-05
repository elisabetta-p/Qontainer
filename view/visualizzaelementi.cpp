#include "visualizzaelementi.h"

visualizzaelementi::visualizzaelementi(ContenutoMultimediale* m, QWidget* parent) : QWidget(parent), multimedia(m) {
    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);

    layout = new QVBoxLayout(this);

    //Creazione del titolo della pagina
    QLabel* titoloFinestra = new QLabel(this);
    titoloFinestra->setText(tr("Visualizza i Contenuti"));
    titoloFinestra->setFont(QFont("Times", 36, QFont::Bold));
    titoloFinestra->setAlignment(Qt::AlignHCenter);
    titoloFinestra->setStyleSheet("QLabel {color : #5a0c31; }");
    layout->addWidget(titoloFinestra);

    griglia = new QGridLayout;
    caricaCampiDaVisualizzare();

    layout->addLayout(griglia);

    QPushButton* goBack = new QPushButton(this);
    goBack->setText("Torna alla schermata principale");

    QPushButton* ricerca = new QPushButton(this);
    ricerca->setText("Fai un'altra ricerca");

    QGridLayout* boxBottoni = new QGridLayout;
    boxBottoni->addWidget(goBack, 0, 0, Qt::AlignCenter);
    boxBottoni->addWidget(ricerca, 1, 0, Qt::AlignCenter);
    boxBottoni->setSizeConstraint(QLayout::SetMinimumSize);
    layout->addLayout(boxBottoni);

    connect (goBack, SIGNAL(clicked()), parent, SLOT(mostraMainWindow()));
    connect (ricerca, SIGNAL(clicked()), parent, SLOT(mostraRicerca()));
}

void visualizzaelementi::creaOpzioneVisualizzazione(QString etichetta, QString valore, int lunghezza, QGridLayout* griglia, int riga) {
    QLabel* label = new QLabel(this);
    label->setText(etichetta);

    QLabel* box = new QLabel(this);
    box->setFixedWidth(lunghezza);
    box->setText(valore);

    //vettoreModifiche.push_back(box);
    griglia->addWidget(label, riga, 0, Qt::AlignLeft);
    griglia->addWidget(box, riga, 1, Qt::AlignLeft);
}

void visualizzaelementi::caricaCampiDaVisualizzare() {
    creaOpzioneVisualizzazione("Titolo:", QString::fromStdString(multimedia->getTitolo()), 250, griglia, 1);
    creaOpzioneVisualizzazione("Durata:", QString::number(multimedia->getDurata()), 250, griglia, 2);
    creaOpzioneVisualizzazione("Genere:", QString::fromStdString(multimedia->getGenere()), 250, griglia, 3);
    creaOpzioneVisualizzazione("Dimensione:", QString::number(multimedia->getDimensione()), 250, griglia, 4);
    creaOpzioneVisualizzazione("Valutazione:", QString::number(multimedia->getValutazione()), 250, griglia, 5);
    creaOpzioneVisualizzazione("Autore:", QString::fromStdString(multimedia->getAutore()), 250, griglia, 6);
    creaOpzioneVisualizzazione("Anno di uscita:", QString::number(multimedia->getDataUscita()), 250, griglia, 7);
    creaOpzioneVisualizzazione("Qualità:", QString::fromStdString(multimedia->qualita()), 250, griglia, 8);
    film* f = dynamic_cast<film*>(multimedia);
    if (f) {
        creaOpzioneVisualizzazione("Risoluzione:", QString::number(f->getRisoluzione()), 250, griglia, 9);
        creaOpzioneVisualizzazione("Regista:",  QString::fromStdString(f->getRegista()), 250, griglia, 10);
        creaOpzioneVisualizzazione("Saga:", QString::fromStdString(f->getSaga()), 250, griglia, 11);
    }
    episodio* e = dynamic_cast<episodio*>(multimedia);
    if (e) {
        creaOpzioneVisualizzazione("Risoluzione:", QString::number(e->getRisoluzione()), 250, griglia, 9);
        creaOpzioneVisualizzazione("Serie:", QString::fromStdString(e->getSerie()), 250, griglia, 10);
        creaOpzioneVisualizzazione("Canale:", QString::fromStdString(e->getCanale()), 250, griglia, 11);
    }
    podcast* p = dynamic_cast<podcast*>(multimedia);
    if (p) {
        creaOpzioneVisualizzazione("Bitrate:", QString::number(p->getBitrate()), 250, griglia, 9);
        creaOpzioneVisualizzazione("Raccolta:", QString::fromStdString(p->getRaccolta()), 250, griglia, 10);
        creaOpzioneVisualizzazione("Ospite:", QString::fromStdString(p->getOspite()), 250, griglia, 11);
    }
    canzone* c = dynamic_cast<canzone*>(multimedia);
    if (c) {
        creaOpzioneVisualizzazione("Bitrate:", QString::number(c->getBitrate()), 250, griglia, 9);
        creaOpzioneVisualizzazione("Album:", QString::fromStdString(c->getAlbum()), 250, griglia, 10);
        creaOpzioneVisualizzazione("Produttore:", QString::fromStdString(c->getProduttore()), 250, griglia, 11);
    }
}
