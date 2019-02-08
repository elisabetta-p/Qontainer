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
    QVBoxLayout* layout;
    QGridLayout* griglia;
    container<ContenutoMultimediale*>* cont;
public:
    risultatoricerca(container<ContenutoMultimediale*>*, QWidget* = nullptr);
    ~risultatoricerca() = default;
};

#endif // RISULTATORICERCA_H
