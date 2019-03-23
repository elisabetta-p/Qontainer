#ifndef RISULTATOELIMINAZIONE_H
#define RISULTATOELIMINAZIONE_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QBoxLayout>
#include "mainwindow.h"

class risultatoeliminazione: public QWidget {
        Q_OBJECT
private:
    QVBoxLayout* layout;
    QGridLayout* griglia;
public:
    risultatoeliminazione(QWidget* = nullptr);
    ~risultatoeliminazione() = default;
};

#endif // RISULTATOELIMINAZIONE_H
