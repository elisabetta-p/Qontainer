#include "ricercaavanzata.h"
#include "mainwindow.h"
ricercaavanzata::ricercaavanzata() {
    setWindowTitle("Qontainer: Ricerca Avanzata - Elisabetta Piombin");
    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);

    //Creazione del titolo Ricerca Avanzata
   QGroupBox* titoloGropuBox = new QGroupBox(this);

   QLabel* titoloFinestra = new QLabel(this);
   titoloFinestra->setMinimumSize(this->width(), 50);
   titoloFinestra->setText(tr("Ricerca Avanzata"));
   titoloFinestra->setFont(QFont("Times", 26, QFont::Bold));

   QHBoxLayout* boxTitolo = new QHBoxLayout;

   boxTitolo->addWidget(titoloFinestra);

   boxTitolo->setSizeConstraint(QLayout::SetMinimumSize);
   titoloGropuBox->setLayout(boxTitolo);
   titoloFinestra->setAlignment(Qt::AlignCenter);

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

   griglia = new QGridLayout;
   griglia->addWidget(menuTendina, 0,0,Qt::AlignLeft);
   griglia->addWidget(autore, 1,0,Qt::AlignLeft);
   griglia->addWidget(titolo, 2,0,Qt::AlignLeft);
   griglia->addWidget(genere, 3,0,Qt::AlignLeft);
   griglia->addWidget(anno, 4,0,Qt::AlignLeft);


   //DESTRA
   //menu a tendina che andrà a sinistra
   QComboBox *opzioni = new QComboBox(this);
   opzioni->insertItem(0, tr("Scegli:"));
   opzioni->insertItem(1, tr("Film"));
   opzioni->insertItem(2, tr("Episodio"));
   opzioni->insertItem(3, tr("Canzoni"));
   opzioni->insertItem(4, tr("Podcast"));


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

   connect(opzioni, SIGNAL(activated(int)), this, SLOT(aggiungiInput(int)));

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

void ricercaavanzata::aggiungiInput(int type) {
       if (type==1) { //film
           QLabel* risoluzione = new QLabel;
           risoluzione->setText("Inserisci la risoluzione: ");
           griglia->addWidget(risoluzione,5,0,Qt::AlignLeft);
           QLineEdit* scriviRisoluzione = new QLineEdit;
           griglia->addWidget(scriviRisoluzione, 5, 1, Qt::AlignLeft);

           QLabel* regista = new QLabel;
           regista->setText("Inserisci il regista: ");
           griglia->addWidget(regista,6,0,Qt::AlignLeft);
           QLineEdit* scriviRegista = new QLineEdit;
           griglia->addWidget(scriviRegista, 6, 1, Qt::AlignLeft);

           QLabel* saga = new QLabel;
           saga->setText("Inserisci la saga: ");
           griglia->addWidget(saga,7,0,Qt::AlignLeft);
           QLineEdit* scriviSaga = new QLineEdit;
           griglia->addWidget(scriviSaga, 7, 1, Qt::AlignLeft);
       }
       if (type==2) { //serie
           QLabel* risoluzione = new QLabel;
           risoluzione->setText("Inserisci la risoluzione: ");
           griglia->addWidget(risoluzione,5,0,Qt::AlignLeft);
           QLineEdit* scriviRisoluzione = new QLineEdit;
           griglia->addWidget(scriviRisoluzione, 5, 1, Qt::AlignLeft);

           QLabel* serie = new QLabel;
           serie->setText("Inserisci la serie: ");
           griglia->addWidget(serie,6,0,Qt::AlignLeft);
           QLineEdit* scriviSerie = new QLineEdit;
           griglia->addWidget(scriviSerie, 6, 1, Qt::AlignLeft);

           QLabel* canale = new QLabel;
           canale->setText("Inserisci il canale, o servizio di streaming: ");
           griglia->addWidget(canale,7,0,Qt::AlignLeft);
           QLineEdit* scriviCanale = new QLineEdit;
           griglia->addWidget(scriviCanale, 7, 1, Qt::AlignLeft);
       }
       if (type==3) { //canzoni

           QLabel* qualita = new QLabel;
           qualita->setText("Inserisci la risoluzione: ");
           griglia->addWidget(qualita,5,0,Qt::AlignLeft);
           QLineEdit* scriviQualita = new QLineEdit;
           griglia->addWidget(scriviQualita , 5, 1, Qt::AlignLeft);

           QLabel* album = new QLabel;
           album->setText("Inserisci l'album: ");
           griglia->addWidget(album,6,0,Qt::AlignLeft);
           QLineEdit* scriviAlbum = new QLineEdit;
           griglia->addWidget(scriviAlbum, 6, 1, Qt::AlignLeft);

           QLabel* produttore = new QLabel;
           produttore->setText("Inserisci il produttore: ");
           griglia->addWidget(produttore,7,0,Qt::AlignLeft);
           QLineEdit* scriviProduttore = new QLineEdit;
           griglia->addWidget(scriviProduttore, 7, 1, Qt::AlignLeft);
       }
       if (type==4) { //podcast
           QLabel* qualita = new QLabel;
           qualita->setText("Inserisci la risoluzione: ");
           griglia->addWidget(qualita,5,0,Qt::AlignLeft);
           QLineEdit* scriviQualita = new QLineEdit;
           griglia->addWidget(scriviQualita , 5, 1, Qt::AlignLeft);

           QLabel* raccolta = new QLabel;
           raccolta->setText("Inserisci la raccolta: ");
           griglia->addWidget(raccolta,6,0,Qt::AlignLeft);
           QLineEdit* scriviRaccolta = new QLineEdit;
           griglia->addWidget(scriviRaccolta, 6, 1, Qt::AlignLeft);

           QLabel* ospite = new QLabel;
           ospite->setText("Inserisci l'ospite: ");
           griglia->addWidget(ospite,7,0,Qt::AlignLeft);
           QLineEdit* scriviOspite = new QLineEdit;
           griglia->addWidget(scriviOspite , 7, 1, Qt::AlignLeft);
       }

}

