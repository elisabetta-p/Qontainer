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

    QWidget* contenitoreRisultati = new QWidget();
    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);


    scrollArea->setWidget(contenitoreRisultati);


    if (!vettoreRisultati.empty()) {
        for (unsigned long i = 0 ; i != vettoreRisultati.size(); ++i ) {

            QLabel* tipo = new QLabel(this);
            //mi scrivo il tipo
            if (dynamic_cast<film*>(vettoreRisultati[i]))
                tipo->setText(QString("Film"));
            if (dynamic_cast<episodio*>(vettoreRisultati[i]))
                tipo->setText(QString("Episodio"));
            if (dynamic_cast<canzone*>(vettoreRisultati[i]))
                tipo->setText(QString("Canzone"));
            if (dynamic_cast<podcast*>(vettoreRisultati[i]))
                tipo->setText(QString("Podcast"));
            QLabel* fileTitolo = new QLabel(this);
            fileTitolo->setText(QString::fromStdString(vettoreRisultati[i]->getTitolo()));
            QLabel* fileAutore = new QLabel(this);
            fileAutore->setText(QString::fromStdString(vettoreRisultati[i]->getAutore()));
            QLabel* fileAnno = new QLabel(this);
            fileAnno->setText(QString::number(vettoreRisultati[i]->getDataUscita()));
            fileTitolo->setAlignment(Qt::AlignHCenter);
            fileAutore->setAlignment(Qt::AlignHCenter);
            fileAnno->setAlignment(Qt::AlignHCenter);

            QLabel* labelTitolo = new QLabel(this);
            QLabel* labelAutore = new QLabel(this);
            QLabel* labelAnno = new QLabel(this);
            QLabel* labelTipo = new QLabel(this);
            labelTitolo->setText(QString("Titolo"));
            labelAutore->setText(QString("Autore"));
            labelAnno->setText(QString("Anno di uscita"));
            labelTipo->setText(QString("Tipo"));

            layoutOrizzontale->addWidget(labelTitolo, 0, 0, Qt::AlignCenter);
            layoutOrizzontale->addWidget(labelAutore, 0, 1, Qt::AlignCenter);
            layoutOrizzontale->addWidget(labelAnno, 0, 2, Qt::AlignCenter);
            layoutOrizzontale->addWidget(labelTipo, 0, 3, Qt::AlignCenter);
            labelTitolo->setStyleSheet("QLabel {color : #cc0066; }");
            labelAnno->setStyleSheet("QLabel {color : #cc0066; }");
            labelTipo->setStyleSheet("QLabel {color : #cc0066; }");
            labelAutore->setStyleSheet("QLabel {color : #cc0066; }");
            labelTitolo->setFont(QFont("Times", 16, QFont::StyleItalic));
            labelAutore->setFont(QFont("Times", 16, QFont::StyleItalic));
            labelAnno->setFont(QFont("Times", 16, QFont::StyleItalic));
            labelTipo->setFont(QFont("Times", 16, QFont::StyleItalic));

            QPushButton* modifica = new QPushButton();
            modifica->setText(QString("Modifica"));

            QPushButton* elimina = new QPushButton();
            elimina->setText(QString("Elimina"));

            layoutOrizzontale->addWidget(fileTitolo, i+1, 0, Qt::AlignCenter);
            layoutOrizzontale->addWidget(fileAutore, i+1, 1, Qt::AlignCenter);
            layoutOrizzontale->addWidget(fileAnno, i+1, 2, Qt::AlignCenter);

            layoutOrizzontale->addWidget(tipo, i+1, 3, Qt::AlignCenter);

            layoutOrizzontale->addWidget(modifica, i+1, 4, Qt::AlignCenter);
            layoutOrizzontale->addWidget(elimina, i+1, 5, Qt::AlignCenter);

            connect(elimina, SIGNAL(clicked()), this, SLOT(schiacciaElimina()));
            connect(this, SIGNAL(inviaEliminazione()), parent, SLOT(mostraEliminazioneRiuscita()));

        }


        layoutVerticale->addWidget(scrollArea);

    }

    contenitoreRisultati->setLayout(layoutOrizzontale);

    if (vettoreRisultati.empty()){
        QLabel* messaggio = new QLabel(this);
        messaggio->setText(QString("Contenuto non presente nella libreria"));
        messaggio->setAlignment(Qt::AlignCenter);
        layoutOrizzontale->addWidget(messaggio, 0, 0, Qt::AlignCenter);
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
/*
void schiacciaElimina(){

}
*/

/*
2 bottoni locali al ciclo for
connect associata al bottone locale craeto in quel ciclo
 */
