#ifndef MODIFICAELEMENTI_H
#define MODIFICAELEMENTI_H
#include "mainwindow.h"
#include <QLineEdit>
#include <QComboBox>
#include <vector>

class modificaelementi: public QWidget{
    Q_OBJECT
private:
    QGridLayout* griglia;
    QGridLayout* grigliaModificaAvanzata;
    QVBoxLayout* layout;
    QComboBox* opzioni;

    void lunghezzaFissaQLineEdit(QLineEdit*, int = 0);

    vector<QLineEdit*> vettoreOpzioni;

    void creaOpzione(QString, QString, int, QGridLayout*, int);
    container<ContenutoMultimediale*>* cont;
    void caricaCampiDaModificare();
    int indice;
    vector<ContenutoMultimediale*> vettRisultati;
public:
    modificaelementi(container<ContenutoMultimediale*>*, int, vector<ContenutoMultimediale*>, QWidget* = nullptr);
    ~modificaelementi() = default;
/*
public slots:
    void modificaInput(int);
private slots:
    void schiacciaModifica();
    void modificaElemento();

signals:
    void inviaModifica();
*/
};

#endif // MODIFICAELEMENTI_H
