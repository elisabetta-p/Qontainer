#include "qontainer.h"
#include <iostream>


qontainer::qontainer()  {
    layoutQ = new QVBoxLayout;
    this->setLayout(layoutQ);
    this->setWindowTitle("Qontainer - Elisabetta Piombin");
    mostraMainWindow();
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
