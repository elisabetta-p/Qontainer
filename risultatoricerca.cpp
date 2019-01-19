#include "risultatoricerca.h"

risultatoricerca::risultatoricerca(QWidget* parent) : QWidget(parent) {
    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);

    layout = new QVBoxLayout(this);

    //Creazione del titolo della pagina dei risultati delle ricerche

    QLabel* titoloFinestra = new QLabel(this);
    titoloFinestra->setText(tr("Risultato ricerca"));
    titoloFinestra->setFont(QFont("Times", 36, QFont::Bold));
    titoloFinestra->setAlignment(Qt::AlignHCenter);
    titoloFinestra->setStyleSheet("QLabel {color : #cc0066; }");

    layout->addWidget(titoloFinestra);

    /*
     * RISULTATI RICERCA:
     * Se c'è stato un risultato, viene visualizzato qua. Altrimenti, esce messaggio "contenuto non presente
     * nella libreria
    */

    //bottoni per tornare alla ricerca, oppure per tornare alla schermata principale

    QPushButton* tornaRicercaAvanzata = new QPushButton(this);
    tornaRicercaAvanzata->setText("Ritorna alla pagina di ricerca avanzata");
    QPushButton* tornaMainWindow = new QPushButton(this);
    tornaMainWindow->setText("Torna alla pagina principale");

    connect(tornaMainWindow, SIGNAL(clicked()), this->parentWidget()->parentWidget(), SLOT(mostraMainWindow()));

    this->setLayout(layout);
}
