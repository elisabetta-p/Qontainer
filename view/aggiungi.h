#ifndef AGGIUNGI_H
#define AGGIUNGI_H
#include "mainwindow.h"
#include <QLineEdit>
#include <QComboBox>
#include <vector>
using std::vector;


class aggiungi: public QWidget {
    Q_OBJECT
private:
    QGridLayout* griglia;
    QGridLayout* grigliaAggiuntaAvanzata;
    QVBoxLayout* layout;

    void lunghezzaFissaQLineEdit(QLineEdit*, int = 0);

    vector<QLineEdit*> vettoreOpzioni;

    void creaOpzione(QString, QString, int, QGridLayout*, int);

public:
    aggiungi(QWidget*);
    ~aggiungi() = default;
private slots:
    void aggiungiInput(int);
};

#endif // AGGIUNGI_H
