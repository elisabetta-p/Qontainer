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
    /*
    void mostraAggiuntaRiuscita(int,
                                string,
                                unsigned short int,
                                string,
                                double,
                                unsigned short int,
                                string,
                                unsigned short int,
                                unsigned int,
                                string,
                                string);//per i film e gli episodi
    void mostraAggiuntaRiuscita(int,
                                string,
                         unsigned short int,
                         string,
                         double, unsigned short int,
                         string,
                         unsigned short int,
                         unsigned short int,
                         string,
                         string); //per canzoni e podcast
    */
};

#endif // QONTAINER_H
