#include "qontainer.h"
#include <iostream>


qontainer::qontainer()  {
    layoutQ = new QVBoxLayout;
    this->setLayout(layoutQ);
    this->setWindowTitle("Qontainer - Elisabetta Piombin");
    mostraMainWindow();

    //genero il contenitore nel costruttore?
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
}

void qontainer::eliminaContenutoAttuale() {
    if(layoutQ) {
        QLayoutItem* item;
        while (item = layoutQ->takeAt(0)) {
            if(dynamic_cast<QWidgetItem*>(item)) {
                QWidget* widgetCorrente = static_cast<QWidget*>(item->widget());
                delete widgetCorrente;
            }
        }
    }
}


void qontainer::mostraMainWindow() {
    eliminaContenutoAttuale();
    mainwindow* newMainWindow = new mainwindow(&contenitore, this);
    layoutQ->addWidget(newMainWindow);
}

void qontainer::mostraRicerca() {
    eliminaContenutoAttuale();
    ricercaavanzata* newRicerca = new ricercaavanzata(&contenitore, this);
    layoutQ->addWidget(newRicerca);
}

void qontainer::mostraAggiungi() {
    eliminaContenutoAttuale();
    aggiungi* newAggiungi = new aggiungi(&contenitore, this);
    layoutQ->addWidget(newAggiungi);
}

//film ed episodi
void qontainer::mostraRisultato(container<ContenutoMultimediale*> contenitore, string titolo, unsigned short int durata, string genere, double dim,
                                unsigned short int val, string autore, unsigned short int data, unsigned int ris, string reg, string saga) {
    eliminaContenutoAttuale();
    risultatoricerca* newRisultato = new risultatoricerca(&contenitore, this);
    layoutQ->addWidget(newRisultato);
    ContenutoMultimediale* f0 = new film ("1", 1, "1",1,1,"1", 1,1,"1","1");
    contenitore.insert(f0);
    ContenutoMultimediale* cercaVideo = new film(titolo, durata, genere, dim, val, autore, data, ris, reg, saga);


    bool trovatoVideo = contenitore.search(cercaVideo);

    if (trovatoVideo)
        std::cout << "Video trovato" << std::endl;
    else
        std::cout << "Video non trovato" << std::endl;

}

//canzoni e podcast
void qontainer::mostraRisultato(container<ContenutoMultimediale*> contenitore, string titolo, unsigned short int durata, string genere, double dim, unsigned short int val,
                                string autore, unsigned short int data, unsigned short int qual, string album, string prod) {
    eliminaContenutoAttuale();
    risultatoricerca* newRisultato = new risultatoricerca(&contenitore, this);
    layoutQ->addWidget(newRisultato);
    ContenutoMultimediale* c0 = new canzone ("1", 1, "1",1,1,"1", 1,1,"1","1");
    contenitore.insert(c0);
    ContenutoMultimediale* cercaAudio = new canzone(titolo, durata, genere, dim, val, autore, data, qual, album, prod);
    bool trovatoAudio = contenitore.search(cercaAudio);
    if (trovatoAudio)
        std::cout << "Audio trovato" << std::endl;
    else
        std::cout << "Audio non trovato" << std::endl;
}

void qontainer::mostraAggiuntaRiuscita() {
    eliminaContenutoAttuale();
    risultatoaggiunta* newAggiunta = new risultatoaggiunta(this);
    layoutQ->addWidget(newAggiunta);
}
/*
void qontainer::mostraProva(int i) {
    std::cout << "mostra: " << i << std::endl;
}
*/
