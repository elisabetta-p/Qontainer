#ifndef RICERCAAVANZATA_H
#define RICERCAAVANZATA_H
#include "mainwindow.h"
#include <QComboBox>
#include <QLineEdit>
#include <QGridLayout>

class ricercaavanzata: public QMainWindow {
    Q_OBJECT
private:
    QGridLayout* griglia;

public:
    ricercaavanzata();
    ~ricercaavanzata() = default;
private slots:
    void tornaAllaMainWindow();
    void aggiungiInput(int);

};

#endif // RICERCAAVANZATA_H
