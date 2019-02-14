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
public slots:
    //void aggiungiInput(int);
    void schiacciaRicerca();

signals:
    void invioRicerca(int, string, string, unsigned short int);
};

#endif // RICERCAAVANZATA_H
