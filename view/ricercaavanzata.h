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

    void creaOpzione(QString, QString, int, QGridLayout*, int);
public:
    ricercaavanzata(QWidget* = nullptr);
    ~ricercaavanzata() = default;
    container<ContenutoMultimediale*> contenitore;
    vector<QLineEdit*> vettoreOpzioni;
private slots:
    void aggiungiInput(int);
    void schiacciaProva(vector <QLineEdit*>);
};

#endif // RICERCAAVANZATA_H
