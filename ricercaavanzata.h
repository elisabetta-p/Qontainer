#ifndef RICERCAAVANZATA_H
#define RICERCAAVANZATA_H
#include "mainwindow.h"
#include <QComboBox>
#include <QLineEdit>

class ricercaavanzata: public QMainWindow {
    Q_OBJECT
public:
    ricercaavanzata();
    ~ricercaavanzata() = default;
private slots:
    void tornaAllaMainWindow();
    void campiGiusti(int, QGridLayout*);

};

#endif // RICERCAAVANZATA_H
