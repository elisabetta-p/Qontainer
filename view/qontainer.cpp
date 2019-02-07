#include "qontainer.h"
#include <iostream>
#include "mainwindow.h"


qontainer::qontainer()  {
    layout = new QVBoxLayout;
    this->setLayout(layout);
    this->setWindowTitle("Qontainer - Elisabetta Piombin");
    mostraMainWindow();
}

void qontainer::eliminaContenutoAttuale() {
    if(layout) {
        QLayoutItem* item;
        while (item = layout->takeAt(0)) {
            if(dynamic_cast<QWidgetItem*>(item)) {
                QWidget* widgetCorrente = static_cast<QWidget*>(item->widget());
                delete widgetCorrente;
            }
        }
    }
}


void qontainer::mostraMainWindow() {
    eliminaContenutoAttuale();
    mainwindow* newMainWindow = new mainwindow(this);
    layout->addWidget(newMainWindow);
}

void qontainer::mostraRicerca() {
    eliminaContenutoAttuale();
    ricercaavanzata* newRicerca = new ricercaavanzata(this);
    layout->addWidget(newRicerca);
}



void qontainer::mostraAggiungi() {
    eliminaContenutoAttuale();
    aggiungi* newAggiungi = new aggiungi(this);
    layout->addWidget(newAggiungi);
}

//film ed episodi
void qontainer::mostraRisultato(container<ContenutoMultimediale*> contenitore, string titolo, unsigned short int durata, string genere, double dim, unsigned short int val, string autore, unsigned short int data, unsigned int ris, string reg, string saga) {
    eliminaContenutoAttuale();
    risultatoricerca* newRisultato = new risultatoricerca(this);
    layout->addWidget(newRisultato);
    film* cercaFilm = new film(titolo, durata, genere, dim, val, autore, data, ris, reg, saga);
    bool trovatoFilm = contenitore.search(cercaFilm);
    if (trovatoFilm) { std::cout << "film trovato";}
    if (!trovatoFilm) {
        episodio* cercaEp = new episodio(titolo, durata, genere, dim, val, autore, data, ris, reg, saga);
        if(contenitore.search(cercaEp)) {
            std::cout << "trovato episodio";
        }
    }
}

//canzoni e podcast
void qontainer::mostraRisultato(container<ContenutoMultimediale*> contenitore, string, unsigned short int, string, double, unsigned short int, string, unsigned short int, unsigned short int, string, string) {
    eliminaContenutoAttuale();
    risultatoricerca* newRisultato = new risultatoricerca(this);
    layout->addWidget(newRisultato);
}

void qontainer::mostraAggiuntaRiuscita() {
    eliminaContenutoAttuale();
    risultatoaggiunta* newAggiunta = new risultatoaggiunta(this);
    layout->addWidget(newAggiunta);
}
/*
void qontainer::mostraProva(int i) {
    std::cout << "mostra: " << i << std::endl;
}
*/
