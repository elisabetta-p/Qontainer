#include "ricercaavanzata.h"
#include "mainwindow.h"
ricercaavanzata::ricercaavanzata() {
    setWindowTitle("Qontainer: Ricerca Avanzata - Elisabetta Piombin");
    setFixedSize(530,530);
    setFocusPolicy(Qt::StrongFocus);

    //Creazione del titolo Ricerca Avanzata
   QGroupBox* titoloGropuBox = new QGroupBox(this);

   QLabel* titoloFinestra = new QLabel(this);
   titoloFinestra->setMinimumSize(this->width(), 30);
   titoloFinestra->setText(tr("Ricerca Avanzata"));
   titoloFinestra->setFont(QFont("Times", 26, QFont::Bold));

   QHBoxLayout* boxTitolo = new QHBoxLayout;

   boxTitolo->addWidget(titoloFinestra);

   boxTitolo->setSizeConstraint(QLayout::SetMinimumSize);
   titoloGropuBox->setLayout(boxTitolo);
   titoloFinestra->setAlignment(Qt::AlignCenter);

   //ora dovrei creare 1 GridLayout 2 colonne, 5 righe

    //DESTRA
   QGroupBox *boxRicerca = new QGroupBox(this);
   QLabel* menuTendina = new QLabel(this);
   menuTendina->setText("Scegli il tipo di file: ");
   QLabel* autore = new QLabel(this);
   autore->setText("Autore:");
   QLabel* titolo = new QLabel(this);
   titolo->setText("Titolo:");
   QLabel* genere = new QLabel(this);
   genere->setText("Genere:");
   QLabel* anno = new QLabel(this);
   anno->setText("Anno di uscita:");

   QGridLayout* griglia = new QGridLayout;
   griglia->addWidget(menuTendina, 0,0,Qt::AlignLeft);
   griglia->addWidget(autore, 1,0,Qt::AlignLeft);
   griglia->addWidget(titolo, 2,0,Qt::AlignLeft);
   griglia->addWidget(genere, 3,0,Qt::AlignLeft);
   griglia->addWidget(anno, 4,0,Qt::AlignLeft);


   //SINISTRA
   //menu a tendina che andrà a sinistra
   QPushButton *scelta = new QPushButton(this);
   QMenu *opzioni = new QMenu(this);
   opzioni->addAction(tr("Film"));
   opzioni->addAction(tr("Serie"));
   opzioni->addAction(tr("Canzoni"));
   opzioni->addAction(tr("Podcast"));
   scelta->setMenu(opzioni);

   scelta->menu();

   connect(scelta, SIGNAL(triggered()), this, SLOT(campiGiusti(scelta, boxRicerca, griglia)));

   QLineEdit* scriviAutore = new QLineEdit(this);
   //scriviAutore->placeholderText();
   QLineEdit* scriviTitolo = new QLineEdit(this);
   //scriviTitolo->placeholderText("Scrivi il titolo di quello che cerchi");
   QLineEdit* scriviGenere = new QLineEdit(this);
   //scriviGenere->placeholderText("Scrivi il genere di quello che cerchi");
   QLineEdit* scriviAnno = new QLineEdit(this);

   griglia->addWidget(scelta, 0, 1, Qt::AlignLeft);
   griglia->addWidget(scriviAutore, 1, 1, Qt::AlignLeft);
   griglia->addWidget(scriviTitolo, 2, 1, Qt::AlignLeft);
   griglia->addWidget(scriviGenere, 3, 1, Qt::AlignLeft);
   griglia->addWidget(scriviAnno, 4, 1, Qt::AlignLeft);

   griglia->setSizeConstraint(QLayout::SetMinimumSize);
   boxRicerca->setLayout(griglia);
   boxRicerca->setMinimumSize(QSize(this->width(), this->height()));

   //aggiunta del bottone cerca
   QGroupBox* gruppoCerca = new QGroupBox(this);

   QPushButton * cercaB = new QPushButton(this);
   cercaB->setText("Cerca");
   QPushButton* goBack = new QPushButton(this);
   goBack->setText("Torna alla schermata principale");

   QGridLayout* boxCerca = new QGridLayout;
   boxCerca->addWidget(cercaB,0,0, Qt::AlignCenter);
   boxCerca->addWidget(goBack,1,0, Qt::AlignCenter);
   boxCerca->setSizeConstraint(QLayout::SetMinimumSize);
   gruppoCerca->setLayout(boxCerca);
   gruppoCerca->setGeometry(0, this->height()-80, this->width(), 0);

   connect (goBack, SIGNAL(clicked()), this, SLOT(tornaAllaMainWindow()));
}

void ricercaavanzata::tornaAllaMainWindow() {
    this->hide();
    mainwindow* newMainW = new mainwindow;
    newMainW->show();
}

void campiGiusti(QPushButton* scelta, QGroupBox* gruppo, QGridLayout* griglia) {
    if (scelta->text() == "Film") {
        //sinistra
        QLabel* saga = new QLabel();
        saga->setText("Saga: ");
        griglia->addWidget(saga, 5, 0, Qt::AlignLeft);

        //destra
        QLineEdit* scriviSaga = new QLineEdit();
        griglia->addWidget(scriviSaga, 5, 1, Qt::AlignLeft);
    }
    if (scelta->text() == "Serie") {

    }
    if (scelta->text() == "Canzoni") {

    }
    if (scelta->text() == "Podcast") {

    }
}