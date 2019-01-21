#ifndef RICERCAAVANZATA_H
#define RICERCAAVANZATA_H
#include "mainwindow.h"
#include <QComboBox>
#include <QLineEdit>
#include <QGridLayout>
#include <vector>
using std::vector;

class ricercaavanzata: public QWidget {
    Q_OBJECT
private:
    QGridLayout* griglia;
    QGridLayout* grigliaRicercaAvanzata;
    QVBoxLayout* layout;

    void lunghezzaFissaQLineEdit(QLineEdit*, int = 0);

    vector<QLineEdit*> vettoreOpzioni;

    void creaOpzione(QString, QString, int, QGridLayout*, int);

public:
    ricercaavanzata(QWidget* = nullptr);
    ~ricercaavanzata() = default;
private slots:
    void aggiungiInput(int);

};

#endif // RICERCAAVANZATA_H
