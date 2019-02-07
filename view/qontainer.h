#ifndef QONTAINER_H
#define QONTAINER_H
#include "mainwindow.h"

class qontainer: public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* layout;
    void eliminaContenutoAttuale();
public:
    qontainer();

public slots:
    void mostraMainWindow();
    void mostraRicerca();
    void mostraAggiungi();
    void mostraRisultato();
    void mostraAggiuntaRiuscita();

    void mostraProva(int i);
};

#endif // QONTAINER_H
