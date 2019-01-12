#include "aggiungi.h"

aggiungi::aggiungi() {
    setWindowTitle("Qontainer: Aggiungi Contenuti - Elisabetta Piombin");
    setFixedSize(530,530);
    setFocusPolicy(Qt::StrongFocus);

    //Creazione del titolo della pagina
   QGroupBox* titoloGropuBox = new QGroupBox(this);

   QLabel* titoloFinestra = new QLabel(this);
   titoloFinestra->setMinimumSize(this->width(), 30);
   titoloFinestra->setText(tr("Aggiungi Contenuti"));
   titoloFinestra->setFont(QFont("Times", 26, QFont::Bold));

   QHBoxLayout* boxTitolo = new QHBoxLayout;

   boxTitolo->addWidget(titoloFinestra);

   boxTitolo->setSizeConstraint(QLayout::SetMinimumSize);
   titoloGropuBox->setLayout(boxTitolo);
   titoloFinestra->setAlignment(Qt::AlignCenter);

   //aggiunta del file
   QGroupBox *boxAggiunta = new QGroupBox(this);
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

   //menu a tendina
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

   griglia->setSizeConstraint(QLayout::SetMinimumSize);
   boxAggiunta->setLayout(griglia);
   boxAggiunta->setMinimumSize(QSize(this->width(), this->height()));

   //aggiunta del bottone aggiungi e del bottone torna indietro
   QGroupBox* gruppoAggiungi = new QGroupBox(this);

   QPushButton* agg = new QPushButton(this);
   agg->setText("Aggiungi");
   QPushButton* goBack = new QPushButton(this);
   goBack->setText("Torna alla schermata principale");

   QGridLayout* boxAggiungi = new QGridLayout;
   boxAggiungi->addWidget(agg,0,0, Qt::AlignCenter);
   boxAggiungi->addWidget(goBack,1,0, Qt::AlignCenter);
   boxAggiungi->setSizeConstraint(QLayout::SetMinimumSize);
   gruppoAggiungi->setLayout(boxAggiungi);
   gruppoAggiungi->setGeometry(0, this->height()-80, this->width(), 0);

   connect (goBack, SIGNAL(clicked()), this, SLOT(tornaAllaMainWindow()));
}

void aggiungi::tornaAllaMainWindow() {
    this->hide();
    mainwindow* newMainW = new mainwindow;
    newMainW->show();
}
