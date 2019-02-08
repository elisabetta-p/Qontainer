#ifndef RISULTATORICERCA_H
#define RISULTATORICERCA_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include "mainwindow.h"


class risultatoricerca: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layoutVerticale;
    QGridLayout* layoutOrizzontale;
    QGridLayout* griglia;
    container<ContenutoMultimediale*>* cont;
    vector<ContenutoMultimediale*> vettoreRisultati;
public:
    risultatoricerca(container<ContenutoMultimediale*>*, vector<ContenutoMultimediale*>, QWidget* = nullptr);
    ~risultatoricerca() = default;
};

#endif // RISULTATORICERCA_H
