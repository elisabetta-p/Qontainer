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
    QVBoxLayout* layout;
    QComboBox* opzioni;

    void lunghezzaFissaQLineEdit(QLineEdit*, int = 0);

    vector<QLineEdit*> vettoreModifiche;

    void creaOpzione(QString, QString, int, QGridLayout*, int);
    void caricaCampiDaModificare();
    ContenutoMultimediale* multimedia;
public:
    modificaelementi(ContenutoMultimediale*, QWidget* = nullptr);
    ~modificaelementi() = default;

private slots:
    void schiacciaModifica();
    void modificaElemento();
signals:
    void inviaModifica();

};

#endif // MODIFICAELEMENTI_H
