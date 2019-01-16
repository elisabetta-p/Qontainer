#include "ricercaavanzata.h"
#include "mainwindow.h"
ricercaavanzata::ricercaavanzata(QWidget* parent) : QWidget(parent) {
    setWindowTitle("Qontainer: Ricerca Avanzata - Elisabetta Piombin");
    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);


    layout = new QVBoxLayout(this);

    //Creazione del titolo Ricerca Avanzata

   QLabel* titoloFinestra = new QLabel(this);
   titoloFinestra->setMinimumSize(this->width(), 50);
   titoloFinestra->setText(tr("Ricerca Avanzata"));
   titoloFinestra->setFont(QFont("Times", 26, QFont::Bold));
   titoloFinestra->setAlignment(Qt::AlignHCenter);


   //QHBoxLayout* boxTitolo = new QHBoxLayout;

   //boxTitolo->addWidget(titoloFinestra);

  // boxTitolo->setSizeConstraint(QLayout::SetMinimumSize);
   layout->addWidget(titoloFinestra);

    //SINISTRA
   //QGroupBox *boxRicerca = new QGroupBox(this);
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
   griglia->setHorizontalSpacing(1);
   layout->addLayout(griglia);


   grigliaRicercaAvanzata = new QGridLayout;
   layout->addLayout(grigliaRicercaAvanzata);
   //boxRicerca->setMinimumSize(QSize(this->width(), this->height()-50));

   //aggiunta del bottone cerca
   //QGroupBox* gruppoCerca = new QGroupBox(this);

   QPushButton * cercaB = new QPushButton(this);
   cercaB->setText("Cerca");
   QPushButton* goBack = new QPushButton(this);
   goBack->setText("Torna alla schermata principale");

   QGridLayout* boxCerca = new QGridLayout;
   boxCerca->addWidget(cercaB,0,0, Qt::AlignCenter);
   boxCerca->addWidget(goBack,1,0, Qt::AlignCenter);
   boxCerca->setSizeConstraint(QLayout::SetMinimumSize);
   layout->addLayout(boxCerca);
   //gruppoCerca->setGeometry(0, this->height()-80, this->width(), 0);

   connect (goBack, SIGNAL(clicked()), this, SLOT(tornaAllaMainWindow()));

   this->setLayout(layout);

}

void ricercaavanzata::tornaAllaMainWindow() {
    this->hide();
    mainwindow* newMainW = new mainwindow;
    newMainW->show();
}

void ricercaavanzata::aggiungiInput(int type) {
    QLayoutItem* item;
    //elimina tutti i qlabel e box di testo del tipo di dato precedente
    while((item = grigliaRicercaAvanzata->takeAt(0))) {
        if(dynamic_cast<QWidgetItem*>(item)) {
            QWidget* widgetCorrente = static_cast<QWidget*>(item->widget());
            grigliaRicercaAvanzata->removeWidget(widgetCorrente);
            delete widgetCorrente;
        }
    }
       if (type==1) { //film
           QLabel* risoluzione = new QLabel;
           risoluzione->setText("Inserisci la risoluzione: ");
           grigliaRicercaAvanzata->addWidget(risoluzione,0,0,Qt::AlignLeft);
           QLineEdit* scriviRisoluzione = new QLineEdit;
           grigliaRicercaAvanzata->addWidget(scriviRisoluzione, 0, 1, Qt::AlignLeft);

           QLabel* regista = new QLabel;
           regista->setText("Inserisci il regista: ");
           grigliaRicercaAvanzata->addWidget(regista,1,0,Qt::AlignLeft);
           QLineEdit* scriviRegista = new QLineEdit;
           grigliaRicercaAvanzata->addWidget(scriviRegista, 1, 1, Qt::AlignLeft);

           QLabel* saga = new QLabel;
           saga->setText("Inserisci la saga: ");
           grigliaRicercaAvanzata->addWidget(saga,2,0,Qt::AlignLeft);
           QLineEdit* scriviSaga = new QLineEdit;
           grigliaRicercaAvanzata->addWidget(scriviSaga, 2, 1, Qt::AlignLeft);
       }
       if (type==2) { //serie
           QLabel* risoluzione = new QLabel;
           risoluzione->setText("Inserisci la risoluzione: ");
           grigliaRicercaAvanzata->addWidget(risoluzione,0,0,Qt::AlignLeft);
           QLineEdit* scriviRisoluzione = new QLineEdit;
           grigliaRicercaAvanzata->addWidget(scriviRisoluzione, 0, 1, Qt::AlignLeft);

           QLabel* serie = new QLabel;
           serie->setText("Inserisci la serie: ");
           grigliaRicercaAvanzata->addWidget(serie,1,0,Qt::AlignLeft);
           QLineEdit* scriviSerie = new QLineEdit;
           grigliaRicercaAvanzata->addWidget(scriviSerie, 1, 1, Qt::AlignLeft);

           QLabel* canale = new QLabel;
           canale->setText("Inserisci il canale, o servizio di streaming: ");
           grigliaRicercaAvanzata->addWidget(canale,2,0,Qt::AlignLeft);
           QLineEdit* scriviCanale = new QLineEdit;
           grigliaRicercaAvanzata->addWidget(scriviCanale, 2, 1, Qt::AlignLeft);
       }
       if (type==3) { //canzoni

           QLabel* qualita = new QLabel;
           qualita->setText("Inserisci la qualità: ");
           grigliaRicercaAvanzata->addWidget(qualita,0,0,Qt::AlignLeft);
           QLineEdit* scriviQualita = new QLineEdit;
           grigliaRicercaAvanzata->addWidget(scriviQualita , 0, 1, Qt::AlignLeft);

           QLabel* album = new QLabel;
           album->setText("Inserisci l'album: ");
           grigliaRicercaAvanzata->addWidget(album,1,0,Qt::AlignLeft);
           QLineEdit* scriviAlbum = new QLineEdit;
           grigliaRicercaAvanzata->addWidget(scriviAlbum, 1, 1, Qt::AlignLeft);

           QLabel* produttore = new QLabel;
           produttore->setText("Inserisci il produttore: ");
           grigliaRicercaAvanzata->addWidget(produttore,2,0,Qt::AlignLeft);
           QLineEdit* scriviProduttore = new QLineEdit;
           grigliaRicercaAvanzata->addWidget(scriviProduttore, 2, 1, Qt::AlignLeft);
       }
       if (type==4) { //podcast
           QLabel* qualita = new QLabel;
           qualita->setText("Inserisci la qualità: ");
           grigliaRicercaAvanzata->addWidget(qualita,0,0,Qt::AlignLeft);
           QLineEdit* scriviQualita = new QLineEdit;
           grigliaRicercaAvanzata->addWidget(scriviQualita , 0, 1, Qt::AlignLeft);

           QLabel* raccolta = new QLabel;
           raccolta->setText("Inserisci la raccolta: ");
           grigliaRicercaAvanzata->addWidget(raccolta,1,0,Qt::AlignLeft);
           QLineEdit* scriviRaccolta = new QLineEdit;
           grigliaRicercaAvanzata->addWidget(scriviRaccolta, 1, 1, Qt::AlignLeft);

           QLabel* ospite = new QLabel;
           ospite->setText("Inserisci l'ospite: ");
           grigliaRicercaAvanzata->addWidget(ospite,2,0,Qt::AlignLeft);
           QLineEdit* scriviOspite = new QLineEdit;
           grigliaRicercaAvanzata->addWidget(scriviOspite , 2, 1, Qt::AlignLeft);
       }
}

