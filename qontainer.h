#ifndef QONTAINER_H
#define QONTAINER_H
#include "mainwindow.h"

class qontainer: public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* layout;
    void eliminaContenutoAttuale();
public:
    qontainer(QWidget* = nullptr);

public slots:
    void schiacciaRicerca();
    void tornaAllaMainWindow();
};

#endif // QONTAINER_H
