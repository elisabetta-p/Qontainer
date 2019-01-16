#include "qontainer.h"
#include "ricercaavanzata.h"

qontainer::qontainer(QWidget* parent)  {
    mainwindow* finestra = new mainwindow(this);
    layout = new QVBoxLayout;
    layout->addWidget(finestra);
    this->setLayout(layout);
}

void qontainer::eliminaContenutoAttuale() {
    if(layout) {
        QLayoutItem* item;
        while (item = layout->takeAt(0)) {
            if(dynamic_cast<QWidgetItem*>(item)) {
                QWidget* widgetCorrente = static_cast<QWidget*>(item->widget());
                widgetCorrente->hide();
                delete widgetCorrente;
            }
        }
    }
}

void qontainer::schiacciaRicerca() {

    eliminaContenutoAttuale();
    ricercaavanzata* newRicerca = new ricercaavanzata(this);
    layout->addWidget(newRicerca);
}


void qontainer::tornaAllaMainWindow() {
    eliminaContenutoAttuale();
    mainwindow* newMainWindow = new mainwindow(this);
    layout->addWidget(newMainWindow);
}
