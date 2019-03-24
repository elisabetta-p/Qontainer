#ifndef QONTAINER_H
#define QONTAINER_H
#include "mainwindow.h"
#include "ricercaavanzata.h"
#include "aggiungi.h"
#include "risultatoaggiunta.h"
#include "risultatoricerca.h"
#include "../model/contenutomultimediale.h"
#include "../model/canzone.h"
#include "../model/podcast.h"
#include "../model/episodio.h"
#include "../model/film.h"
#include "modificaelementi.h"
#include "risultatoeliminazione.h"
#include <iostream>

class qontainer: public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* layoutQ;
    void eliminaContenutoAttuale();
    container<ContenutoMultimediale*> contenitore;
public:
    qontainer();
    vector<ContenutoMultimediale*> vettoreRisultatiRicerca;
public slots:
    void mostraMainWindow();
    void mostraRicerca();
    void mostraAggiungi();
    void mostraRisultato(string,
                         string,
                         unsigned short int);
    void mostraAggiuntaRiuscita();
    void mostraEliminazioneRiuscita();
    void mostraModificaElementi(ContenutoMultimediale*);
};

#endif // QONTAINER_H
