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

    //SINISTRA
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


   //DESTRA
   //menu a tendina che andrà a sinistra
   QComboBox *opzioni = new QComboBox(this);
   opzioni->insertItem(0, tr("Film"));
   opzioni->insertItem(1, tr("Episodio"));
   opzioni->insertItem(2, tr("Canzoni"));
   opzioni->insertItem(3, tr("Podcast"));


   QLineEdit* scriviAutore = new QLineEdit(this);
   //scriviAutore->placeholderText();
   QLineEdit* scriviTitolo = new QLineEdit(this);
   //scriviTitolo->placeholderText("Scrivi il titolo di quello che cerchi");
   QLineEdit* scriviGenere = new QLineEdit(this);
   //scriviGenere->placeholderText("Scrivi il genere di quello che cerchi");
   QLineEdit* scriviAnno = new QLineEdit(this);

   griglia->addWidget(opzioni, 0, 1, Qt::AlignLeft);
   griglia->addWidget(scriviAutore, 1, 1, Qt::AlignLeft);
   griglia->addWidget(scriviTitolo, 2, 1, Qt::AlignLeft);
   griglia->addWidget(scriviGenere, 3, 1, Qt::AlignLeft);
   griglia->addWidget(scriviAnno, 4, 1, Qt::AlignLeft);

   connect(opzioni, SIGNAL(QComboBox::activated(int i)), this, SLOT(campiGiusti(i, griglia)));

   griglia->setSizeConstraint(QLayout::SetMinimumSize);
   boxRicerca->setLayout(griglia);
   boxRicerca->setMinimumSize(QSize(this->width(), this->height()-50));

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

void ricercaavanzata::campiGiusti(int i, QGridLayout* griglia) {
    if (i==0) { //film
        QLabel* saga = new QLabel;
        saga->setText("Inserisci la saga: ");
        griglia->addWidget(saga,5,0,Qt::AlignLeft);

    }
    if (i==1) { //serie
        QLabel* serie = new QLabel;
        serie->setText("Inserisci la serie: ");
        griglia->addWidget(serie,5,0,Qt::AlignLeft);
    }
    if (i==2) { //canzoni
        QLabel* album = new QLabel;
        album->setText("Inserisci l'album: ");
        griglia->addWidget(album,5,0,Qt::AlignLeft);
    }
    if (i==3) { //podcast
        QLabel* raccolta = new QLabel;
        raccolta->setText("Inserisci la serie: ");
        griglia->addWidget(raccolta,5,0,Qt::AlignLeft);
    }
}
