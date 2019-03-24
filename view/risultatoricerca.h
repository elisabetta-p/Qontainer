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
    QScrollArea* scrollArea;
    //QTextBrowser* scrollAreaTitolo, *scrollAreaAutore, *scrollAreaAnno, *scrollAreaTipo;
    container<ContenutoMultimediale*>* cont;
    vector<ContenutoMultimediale*> vettoreRisultati;
    QFrame* inner;
    int elementoDaEliminare;
public:
    risultatoricerca(container<ContenutoMultimediale*>*, vector<ContenutoMultimediale*>, QWidget* = nullptr);
    ~risultatoricerca() = default;
private slots:
    void eliminaElemento();
    void schiacciaElimina();
    void schiacciaModifica();
signals:
    void inviaEliminazione();
    void inviaModifica(int, vector<ContenutoMultimediale*>);
};

#endif // RISULTATORICERCA_H
