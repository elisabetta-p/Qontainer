#ifndef QONTAINER_H
#define QONTAINER_H
#include "mainwindow.h"
#include "ricercaavanzata.h"
#include "aggiungi.h"
#include "risultatoaggiunta.h"
#include "risultatoricerca.h"

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
    void mostraRisultato(container<ContenutoMultimediale*>,
                         string,
                         unsigned short int,
                         string,
                         double,
                         unsigned short int,
                         string,
                         unsigned short int,
                         unsigned int,
                         string,
                         string);  //per i film e gli episodi
    void mostraRisultato(container<ContenutoMultimediale*>,
                         string,
                         unsigned short int,
                         string,
                         double, unsigned short int,
                         string,
                         unsigned short int,
                         unsigned short int,
                         string,
                         string); //per canzoni e podcast
    void mostraAggiuntaRiuscita();

    //void mostraProva(int i);
};

#endif // QONTAINER_H
