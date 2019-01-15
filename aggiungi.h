#ifndef AGGIUNGI_H
#define AGGIUNGI_H
#include "mainwindow.h"
#include <QLineEdit>
#include <QComboBox>


class aggiungi: public QMainWindow {
    Q_OBJECT
private:
    QGridLayout* griglia;
public:
    aggiungi();
    ~aggiungi() = default;
private slots:
    void tornaAllaMainWindow();
    void aggiungiInput(int);
};

#endif // AGGIUNGI_H
