#include "mainwindow.h"

/*
mainwindow::mainwindow(QLabel ti, QPushButton ric, QPushButton agg, QLabel li, QLabel art, QLabel fi ,QLabel ser, QLabel pod, QVBoxLayout lAr, QVBoxLayout lFi, QVBoxLayout lSe, QVBoxLayout lPo) :
                        titoloFinestra(ti), ricerca(ric), aggiungi(agg), lib(li), artisti(art), film(fi), serie (ser), podcast(pod), layoutArtisti(lAr), layoutFilm(lFi), layoutSerie(lSe), layoutPodcast(lPo) {}

*/

mainwindow::mainwindow(QWidget* parent ) : QMainWindow (parent) {
    setWindowTitle("Qontainer - Elisabetta Piombin");
    setFixedSize(700,500);
    setFocusPolicy(Qt::StrongFocus);

    creaTitolo();
    creaBottoni();

}

void mainwindow::creaTitolo() {
    QLabel* titolo = new QLabel(this);
    titolo->setMinimumSize(200, 100);
    titolo->setText(tr("Qontainer"));
    QFont fontTitolo ("Times", 36, QFont::Bold);
    titolo->setFont(fontTitolo);
    titolo->setAlignment(Qt::AlignCenter);
}

void mainwindow::creaBottoni() {
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
    gruppoBottoni->setMinimumSize(QSize(700,200));
}
