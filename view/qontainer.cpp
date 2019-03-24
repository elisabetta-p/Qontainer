#include "qontainer.h"
#include <iostream>


qontainer::qontainer()  {
    layoutQ = new QVBoxLayout;
    this->setLayout(layoutQ);
    this->setWindowTitle("Qontainer - Elisabetta Piombin");
    mostraMainWindow();

    //genero il contenitore nel costruttore?
    ContenutoMultimediale* f1 = new film ("iron man 1", 126, "azione",1500.0,5,"Marvel", 0,1080,"Joss Whedon","MCU");
    ContenutoMultimediale* f2 = new film ("iron man 3", 127, "azione", 4585.5, 9, "Marvel", 0, 1080, "Tizio", "MCU");
    ContenutoMultimediale* c1 = new canzone ("Organs",3, "Indie", 3.5,8,"Of Monsters and Men", 2016, 125, "Beneath the skin", "nd");
    ContenutoMultimediale* f3 = new film ("iron man 2", 127, "azione", 4585.5, 9, "Marvel", 0, 1080, "Tizio", "MCU");
    ContenutoMultimediale* f4 = new film ("iron man 4", 127, "azione", 4585.5, 9, "Marvel", 0, 1080, "Tizio", "MCU");
    ContenutoMultimediale* p1 = new podcast ("getting curious", 40, "info", 123, 9, "JVN", 2019, 450, "getting curious with jvn", "tizio");
    ContenutoMultimediale* s1 = new episodio ("episodio 1", 40, "commedia", 400, 7, "Tizio", 2018, 789, "serie1", "netflix");
    ContenutoMultimediale* c0 = new canzone ("1", 1, "1",1,1,"1", 1,1,"1","1");
    ContenutoMultimediale* f5 = new film ("1", 1, "1",1,1,"1", 1,1,"1","1");

    contenitore.insert(c0);
    contenitore.insert(f1);
    contenitore.insert(f2);
    contenitore.insert(c1);
    contenitore.insert(f3);
    contenitore.insert(f4);
    contenitore.insert(p1);
    contenitore.insert(s1);
    contenitore.insert(f5);
}

void qontainer::eliminaContenutoAttuale() {
    if(layoutQ) {
        QLayoutItem* item;
        while ((item = layoutQ->takeAt(0))) {
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
void qontainer::mostraRisultato(string titolo, string autore, unsigned short int data) {
    ContenutoMultimediale* cercaContenuto = new film(titolo, autore, data);
    vettoreRisultatiRicerca = contenitore.search(cercaContenuto);

    eliminaContenutoAttuale();
    risultatoricerca* newRisultato = new risultatoricerca(&contenitore, vettoreRisultatiRicerca, this);
    layoutQ->addWidget(newRisultato);

}

void qontainer::mostraAggiuntaRiuscita() {
    eliminaContenutoAttuale();
    risultatoaggiunta* newAggiunta = new risultatoaggiunta(this);
    layoutQ->addWidget(newAggiunta);
}

void qontainer::mostraEliminazioneRiuscita() {
    eliminaContenutoAttuale();
    risultatoeliminazione* newEliminazione = new risultatoeliminazione(this);
    layoutQ->addWidget(newEliminazione);
}

void qontainer::mostraModificaElementi(ContenutoMultimediale* m) {
    eliminaContenutoAttuale();
    modificaelementi* newModificaElementi = new modificaelementi(m, this);
    layoutQ->addWidget(newModificaElementi);
}

void qontainer::mostraModificaRiuscita() {
    eliminaContenutoAttuale();
    risultatomodifica* newRisultatoModifica = new risultatomodifica();
    layoutQ->addWidget(newRisultatoModifica);
}
