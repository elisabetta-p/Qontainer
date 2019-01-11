#ifndef AGGIUNGI_H
#define AGGIUNGI_H
#include "mainwindow.h"
#include <QLineEdit>
#include <QMenu>


class aggiungi: public QMainWindow {
    Q_OBJECT
public:
    aggiungi();
    ~aggiungi() = default;
private slots:
    void tornaAllaMainWindow();

};

#endif // AGGIUNGI_H
