#include "qontainer.h"
#include <iostream>

// Implementazione metodo protetto closeEvent
void qontainer::closeEvent(QCloseEvent* event) {
    db->save(contenitore);
    event->accept();
}

qontainer::qontainer()  {
    layoutQ = new QVBoxLayout;
    this->setLayout(layoutQ);
    this->setWindowTitle("Qontainer - Elisabetta Piombin");

    db = new database("./db.txt", '|');
    db->load(contenitore);
    mostraMainWindow();
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

void qontainer::mostraVisualizzazione(ContenutoMultimediale* m) {
    eliminaContenutoAttuale();
    visualizzaelementi* newVisualizzeElementi = new visualizzaelementi(m, this);
    layoutQ->addWidget(newVisualizzeElementi);
}

void qontainer::mostraModificaRiuscita() {
    eliminaContenutoAttuale();
    risultatomodifica* newRisultatoModifica = new risultatomodifica(this);
    layoutQ->addWidget(newRisultatoModifica);
}
