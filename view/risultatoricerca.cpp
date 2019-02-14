#include "risultatoricerca.h"
#include <typeinfo>

risultatoricerca::risultatoricerca(container<ContenutoMultimediale*>* p_container, vector<ContenutoMultimediale*> risultati, QWidget* parent) : QWidget(parent), cont(p_container), vettoreRisultati(risultati)
{
    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);

    layoutVerticale = new QVBoxLayout(this);

    //Creazione del titolo della pagina dei risultati delle ricerche

    QLabel* titoloFinestra = new QLabel(this);
    titoloFinestra->setText(tr("Risultato ricerca"));
    titoloFinestra->setFont(QFont("Times", 36, QFont::Bold));
    titoloFinestra->setAlignment(Qt::AlignHCenter);
    titoloFinestra->setStyleSheet("QLabel {color : #cc0066; }");

    layoutVerticale->addWidget(titoloFinestra);
    layoutOrizzontale=new QGridLayout;

    /*
     * RISULTATI RICERCA:
     * Se c'è stato un risultato, viene visualizzato qua. Altrimenti, esce messaggio "contenuto non presente
     * nella libreria
    */

    for (unsigned long i = 0 ; i != vettoreRisultati.size(); ++i ) {
        QLabel* tipo = new QLabel(this);
        tipo->setText(QString::fromStdString(typeid(*(vettoreRisultati[i])).name()));

        QLabel* fileTitolo = new QLabel(this);
        fileTitolo->setText(QString::fromStdString(vettoreRisultati[i]->getTitolo()));

        QLabel* fileAutore = new QLabel(this);
        fileAutore->setText(QString::fromStdString(vettoreRisultati[i]->getAutore()));

        QLabel* fileAnno = new QLabel(this);
        fileAnno->setText(QString::number(vettoreRisultati[i]->getDataUscita()));

        fileTitolo->setAlignment(Qt::AlignHCenter);
        fileAutore->setAlignment(Qt::AlignHCenter);
        fileAnno->setAlignment(Qt::AlignHCenter);


        layoutOrizzontale->addWidget(fileTitolo, i, 0, Qt::AlignCenter);
        layoutOrizzontale->addWidget(fileAutore, i, 1, Qt::AlignCenter);
        layoutOrizzontale->addWidget(fileAnno, i, 2, Qt::AlignCenter);
        layoutOrizzontale->addWidget(tipo, i, 3, Qt::AlignCenter);


        layoutVerticale->addLayout(layoutOrizzontale);
    }



    //bottoni per tornare alla ricerca, oppure per tornare alla schermata principale
    QPushButton* tornaRicercaAvanzata = new QPushButton(this);
    tornaRicercaAvanzata->setText("Ritorna alla pagina di ricerca avanzata");
    QPushButton* tornaMainWindow = new QPushButton(this);
    tornaMainWindow->setText("Torna alla pagina principale");

    griglia = new QGridLayout;
    griglia->addWidget(tornaRicercaAvanzata, 0, 0, Qt::AlignCenter);
    griglia->addWidget(tornaMainWindow, 1, 0, Qt::AlignCenter);
    layoutVerticale->addLayout(griglia);

    connect(tornaMainWindow, SIGNAL(clicked()), parent, SLOT(mostraMainWindow()));
    connect(tornaRicercaAvanzata, SIGNAL(clicked()), parent, SLOT(mostraRicerca()));
    this->setLayout(layoutVerticale);
}
