#ifndef RISULTATORICERCA_H
#define RISULTATORICERCA_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include "mainwindow.h"
#include <QScrollArea>
#include <QFrame>


class risultatoricerca: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layoutVerticale;
    QGridLayout* layoutOrizzontale;
    QGridLayout* griglia;
    //QScrollArea* scrollArea;
    //QTextBrowser* scrollAreaTitolo, *scrollAreaAutore, *scrollAreaAnno, *scrollAreaTipo;
    QScrollArea* scrollArea;
    container<ContenutoMultimediale*>* cont;
    vector<ContenutoMultimediale*> vettoreRisultati;
    QFrame* inner;
public:
    risultatoricerca(container<ContenutoMultimediale*>*, vector<ContenutoMultimediale*>, QWidget* = nullptr);
    ~risultatoricerca() = default;

};

#endif // RISULTATORICERCA_H
