#include "risultatoeliminazione.h"

risultatoeliminazione::risultatoeliminazione(QWidget* parent) : QWidget(parent) {
    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);

    layout = new QVBoxLayout(this);

    QLabel* titoloFinestra = new QLabel(this);
    titoloFinestra->setText(tr("Conferma eliminazione"));
    titoloFinestra->setFont(QFont("Times", 36, QFont::Bold));
    titoloFinestra->setAlignment(Qt::AlignHCenter);
    titoloFinestra->setStyleSheet("QLabel {color : #5a0c31; }");

    layout->addWidget(titoloFinestra);

    QLabel* messaggioDiConferma = new QLabel(this);
    messaggioDiConferma->setFont(QFont("Times", 18));
    messaggioDiConferma->setText("Il contenuto e' stato eliminato con successo!");
    messaggioDiConferma->setStyleSheet("QLabel{color:#3f1b35;}");
    messaggioDiConferma->setAlignment(Qt::AlignHCenter);
    layout->addWidget(messaggioDiConferma);

    QPushButton* tornaRicerca = new QPushButton(this);
    tornaRicerca->setText("Ritorna alla pagina di ricerca avanzata");
    QPushButton* tornaMainWindow = new QPushButton(this);
    tornaMainWindow->setText("Torna alla pagina principale");

    griglia = new QGridLayout;
    griglia->addWidget(tornaRicerca, 0, 0, Qt::AlignCenter);
    griglia->addWidget(tornaMainWindow, 1, 0, Qt::AlignCenter);
    layout->addLayout(griglia);

    connect(tornaMainWindow, SIGNAL(clicked()), parent, SLOT(mostraMainWindow()));
    connect(tornaRicerca, SIGNAL(clicked()), parent, SLOT(mostraRicerca()));
    this->setLayout(layout);

}
