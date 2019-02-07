#include "qontainer.h"
#include <iostream>
#include "ricercaavanzata.h"
#include "aggiungi.h"
#include "risultatoricerca.h"
#include "risultatoaggiunta.h"

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

void qontainer::mostraRisultato() {
    eliminaContenutoAttuale();
    risultatoricerca* newRisultato = new risultatoricerca(this);
    layout->addWidget(newRisultato);
}

void qontainer::mostraAggiuntaRiuscita() {
    eliminaContenutoAttuale();
    risultatoaggiunta* newAggiunta = new risultatoaggiunta(this);
    layout->addWidget(newAggiunta);
}

void qontainer::mostraProva(int i) {
    std::cout << "mostra: " << i << std::endl;
}
