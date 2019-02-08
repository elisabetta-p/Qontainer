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
    QComboBox* opzioni;

    void lunghezzaFissaQLineEdit(QLineEdit*, int = 0);

    vector<QLineEdit*> vettoreOpzioni;

    void creaOpzione(QString, QString, int, QGridLayout*, int);
    container<ContenutoMultimediale*>* cont;

public:
    aggiungi(container<ContenutoMultimediale*>*, QWidget* = nullptr);
    ~aggiungi() = default;
public slots:
    void aggiungiInput(int);
    void schiacciaAggiungi();
signals:
    void invioAggiunta(int, string, unsigned short int, string, double, unsigned short int, string, unsigned short int, unsigned int, string, string); //per i film e gli episodi
    void invioAggiunta(int, string, unsigned short int, string, double, unsigned short int, string, unsigned short int, unsigned short int, string, string);//per le canzoni e i podcast
    //per i podcast
};

#endif // AGGIUNGI_H
