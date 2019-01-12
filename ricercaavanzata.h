#ifndef RICERCAAVANZATA_H
#define RICERCAAVANZATA_H
#include "mainwindow.h"
#include <QMenu>
#include <QLineEdit>

class ricercaavanzata: public QMainWindow {
    Q_OBJECT
private:

public:
    ricercaavanzata();
    ~ricercaavanzata() = default;
    QMenu* opzioni;
private slots:
    void tornaAllaMainWindow();
    void campiGiusti(QPushButton*, QGroupBox*, QGridLayout*);

};

#endif // RICERCAAVANZATA_H
