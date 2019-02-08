#ifndef RICERCAAVANZATA_H
#define RICERCAAVANZATA_H
#include "mainwindow.h"
#include "../model/container.h"
#include <QComboBox>
#include <QLineEdit>
#include <vector>
using std::vector;

class ricercaavanzata: public QWidget {
    Q_OBJECT
private:
    QGridLayout* griglia;
    QGridLayout* grigliaRicercaAvanzata;
    QVBoxLayout* layout;
    vector<QLineEdit*> vettoreOpzioni;
    void creaOpzione(QString, QString, int, QGridLayout*, int);
    QComboBox* opzioni;
    container<ContenutoMultimediale*>* cont;
public:
    ricercaavanzata(container<ContenutoMultimediale*>*, QWidget* = nullptr);
    ~ricercaavanzata() = default;
    container<ContenutoMultimediale*> contenitore;
public slots:
    void aggiungiInput(int);
    void schiacciaRicerca();

signals:
    void invioRicerca(string, unsigned short int, string, double, unsigned short int, string, unsigned short int, unsigned int, string, string); //per i film e gli episodi
    void invioRicerca(string, unsigned short int, string, double, unsigned short int, string, unsigned short int, unsigned short int, string, string);//per le canzoni e i podcast
    //per i podcast
};

#endif // RICERCAAVANZATA_H
