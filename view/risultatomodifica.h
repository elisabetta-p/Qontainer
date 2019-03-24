#ifndef MODIFICARIUSCITA_H
#define MODIFICARIUSCITA_H
#include "mainwindow.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QBoxLayout>

class risultatomodifica: public QWidget {
private:
    QVBoxLayout* layout;
    QGridLayout* griglia;
public:
    risultatomodifica(QWidget* = nullptr);
    ~risultatomodifica() = default;
};

#endif // MODIFICARIUSCITA_H
