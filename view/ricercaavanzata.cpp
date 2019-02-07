#include "ricercaavanzata.h"
#include "mainwindow.h"
#include "risultatoricerca.h"
#include <iostream>


ricercaavanzata::ricercaavanzata(QWidget* parent) : QWidget(parent) {
    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);


    layout = new QVBoxLayout(this);

    //Creazione del titolo Ricerca Avanzata
   QLabel* titoloFinestra = new QLabel(this);
   titoloFinestra->setText(tr("Ricerca Avanzata"));
   titoloFinestra->setFont(QFont("Times", 36, QFont::Bold));
   titoloFinestra->setAlignment(Qt::AlignHCenter);
   titoloFinestra->setStyleSheet("QLabel {color : #cc0066; }");

   layout->addWidget(titoloFinestra);


   griglia = new QGridLayout;

   QLabel* menuTendina = new QLabel(this);
   menuTendina->setText("Scegli il tipo di file che vuoi cercare: ");
   griglia->addWidget(menuTendina, 0,0,Qt::AlignLeft);

   //menu a tendina che andrà a destra
   QComboBox *opzioni = new QComboBox(this);
   opzioni->insertItem(0, tr("Scegli:"));
   opzioni->insertItem(1, tr("Film"));
   opzioni->insertItem(2, tr("Episodio"));
   opzioni->insertItem(3, tr("Canzoni"));
   opzioni->insertItem(4, tr("Podcast"));

   griglia->addWidget(opzioni, 0, 1, Qt::AlignLeft);


    //Creazione dei vari campi e delle text box
   creaOpzione("Autore:", "Inserisci l'autore", 250, griglia, 1);
   creaOpzione("Titolo:", "Inserisci il titolo", 250, griglia, 2);
   creaOpzione("Genere:", "Inserisci il genere", 250, griglia, 3);
   creaOpzione("Anno di uscita:", "Inserisci l'anno", 250, griglia, 4);

   connect(opzioni, SIGNAL(activated(int)), this, SLOT(aggiungiInput(int)));

   layout->addLayout(griglia);


   grigliaRicercaAvanzata = new QGridLayout;
   layout->addLayout(grigliaRicercaAvanzata);

   QPushButton* cercaB = new QPushButton(this);
   cercaB->setText("Cerca");
   QPushButton* goBack = new QPushButton(this);
   goBack->setText("Torna alla schermata principale");


   //BOTTONE DI PROVA PER LA RICERCA EFFETTIVA
   QPushButton* provaB = new QPushButton(this);
   provaB->setText("prova");


   QGridLayout* boxCerca = new QGridLayout;
   boxCerca->addWidget(cercaB,0,0, Qt::AlignCenter);
   boxCerca->addWidget(goBack,1,0, Qt::AlignCenter);


   //BOTTONE DI PROVA NEL LAYOUT BOTTONI
   boxCerca->addWidget(provaB,2,0,Qt::AlignCenter);


   boxCerca->setSizeConstraint(QLayout::SetMinimumSize);
   layout->addLayout(boxCerca);

   connect (cercaB, SIGNAL(clicked()), parent, SLOT(mostraRisultato()));
   connect (goBack, SIGNAL(clicked()), parent, SLOT(mostraMainWindow()));


   //CONNECT DI PROVA COL BOTTONE DI PROVA
   connect(provaB, SIGNAL(clicked()), parent, SLOT(schiacciaProva(vettoreOpzioni)));


   this->setLayout(layout);

   //provo a fare la ricerca. intanto mi creo e mi riempio un contenitore
   ContenutoMultimediale* f1 = new film ("iron man111", 126, "azione",1500.0,5,"Marvel", 2012,1080,"Joss Whedon","MCU");
   ContenutoMultimediale* f2 = new film ("iron man 3", 127, "azione", 4585.5, 9, "Marvel", 1013, 1080, "Tizio", "MCU");
   ContenutoMultimediale* c1 = new canzone ("Organs",3, "Indie", 3.5,8,"Of Monsters and Men", 2016, 125, "Beneath the skin", "nd");
   ContenutoMultimediale* f3 = new film ("iron man 2", 127, "azione", 4585.5, 9, "Marvel", 1013, 1080, "Tizio", "MCU");
   ContenutoMultimediale* f4 = new film ("iron man 4", 127, "azione", 4585.5, 9, "Marvel", 1013, 1080, "Tizio", "MCU");
   ContenutoMultimediale* p1 = new podcast ("getting curious", 40, "info", 123, 9, "JVN", 2019, 450, "getting curious with jvn", "tizio");
   ContenutoMultimediale* s1 = new episodio ("episodio 1", 40, "commedia", 400, 7, "Tizio", 2018, 789, "serie1", "netflix");

   contenitore.insert(f1);
   contenitore.insert(f2);
   contenitore.insert(c1);
   contenitore.insert(f3);
   contenitore.insert(f4);
   contenitore.insert(p1);
   contenitore.insert(s1);

   // metodo che dovrei usare ? QLineEdit->text().toStdString()
   // per la combobox currentIntex()
   // come accidenti mi prendo le stringhe dalle qlineedit se le ho create con una funzione???


}



void ricercaavanzata::aggiungiInput(int type) {
    //elimina tutti i qlabel e box di testo del tipo di dato precedente
    QLayoutItem* item;
    while((item = grigliaRicercaAvanzata->takeAt(0))) {

        if(dynamic_cast<QWidgetItem*>(item)) {
            QWidget* widgetCorrente = static_cast<QWidget*>(item->widget());
            widgetCorrente->hide();
            grigliaRicercaAvanzata->removeWidget(widgetCorrente);

            //se item è un QLineEdit lo devo rimuovere dal vettoreOpzioni e distruggerlo
            if(dynamic_cast<QLineEdit*>(item->widget())) {
                QLineEdit* lineEditCorrente = static_cast<QLineEdit*>(item->widget());
                for(auto it = vettoreOpzioni.begin(); it != vettoreOpzioni.end(); ++it) {
                    if(*it == lineEditCorrente) {
                        vettoreOpzioni.erase(it);
                        --it;
                    }
                }
            }
            else { //se non è un QLineEdit, item è un QLabel => lo distruggo manualmente
                delete widgetCorrente;
            }
       }
    }
       if (type==1) { //film
            creaOpzione("Risoluzione:", "Inserisci la risoluzione", 250, grigliaRicercaAvanzata, 0);
            creaOpzione("Regista:", "Inserisci il regista", 250, grigliaRicercaAvanzata, 1);
            creaOpzione("Saga:", "Inserisci la saga", 250, grigliaRicercaAvanzata, 2);
       }
       if (type==2) { //serie
           creaOpzione("Risoluzione:", "Inserisci la risoluzione", 250, grigliaRicercaAvanzata, 0);
           creaOpzione("Serie:", "Inserisci la serie", 250, grigliaRicercaAvanzata, 1);
           creaOpzione("Canale:", "Inserisci il canale o servizio di streaming", 250, grigliaRicercaAvanzata, 2);
       }
       if (type==3) { //canzoni
           creaOpzione("Qualità:", "Inserisci la qualità", 250, grigliaRicercaAvanzata, 0);
           creaOpzione("Album:", "Inserisci l'album", 250, grigliaRicercaAvanzata, 1);
           creaOpzione("Produttore:", "Inserisci il produttore", 250, grigliaRicercaAvanzata, 2);
       }
       if (type==4) { //podcast
           creaOpzione("Qualità:", "Inserisci la qualità", 250, grigliaRicercaAvanzata, 0);
           creaOpzione("Raccolta:", "Inserisci la raccolta", 250, grigliaRicercaAvanzata, 1);
           creaOpzione("Ospite:", "Inserisci l'ospite", 250, grigliaRicercaAvanzata, 2);
       }
}

void ricercaavanzata::creaOpzione(QString etichetta, QString placeholder, int lunghezza, QGridLayout* griglia, int riga) {
    QLabel* label = new QLabel(this);
    label->setText(etichetta);

    QLineEdit* box = new QLineEdit(this);
    box->setFixedWidth(lunghezza);
    box->setPlaceholderText(placeholder);
    //artista = box->text().toStdString();

    vettoreOpzioni.push_back(box);


    griglia->addWidget(label, riga, 0, Qt::AlignLeft);
    griglia->addWidget(box, riga, 1, Qt::AlignLeft);

/*
    for (unsigned long i = 0; i < vettoreOpzioni.size(); ++i) {
        std::cout << vettoreTesti[i] << std::endl;
    }
    */
}

void ricercaavanzata::schiacciaProva(vector<QLineEdit*> vettoreOpzioni) {
    for (unsigned long i=0; i!=vettoreOpzioni.size(); ++i) {
        cout << vettoreOpzioni[i]->text().toStdString() << std::endl;
    }
}

