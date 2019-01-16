#ifndef RICERCAAVANZATA_H
#define RICERCAAVANZATA_H
#include "mainwindow.h"
#include <QComboBox>
#include <QLineEdit>
#include <QGridLayout>

class ricercaavanzata: public QWidget {
    Q_OBJECT
private:
    QGridLayout* griglia;
    QGridLayout* grigliaRicercaAvanzata;
    QVBoxLayout* layout;
public:
    ricercaavanzata(QWidget* = nullptr);
    ~ricercaavanzata() = default;
private slots:
    void tornaAllaMainWindow();
    void aggiungiInput(int);

};

#endif // RICERCAAVANZATA_H
