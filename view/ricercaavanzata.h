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
public:
    ricercaavanzata(QWidget* = nullptr);
    ~ricercaavanzata() = default;
    container<ContenutoMultimediale*> contenitore;
public slots:
    void aggiungiInput(int);
    void schiacciaProva();

signals:
    void invioProva(int);
};

#endif // RICERCAAVANZATA_H
