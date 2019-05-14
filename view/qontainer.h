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
#include "../model/database.h"
#include "modificaelementi.h"
#include "risultatoeliminazione.h"
#include "risultatomodifica.h"
#include "visualizzaelementi.h"
#include <iostream>
#include <QCloseEvent>

class qontainer: public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* layoutQ;
    void eliminaContenutoAttuale();
    container<ContenutoMultimediale*> contenitore;
    database* db;

protected:
    // Override del metodo closeEvent di QWidget
    void closeEvent(QCloseEvent*) override;
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
    void mostraModificaRiuscita();
    void mostraVisualizzazione(ContenutoMultimediale*);
};

#endif // QONTAINER_H
