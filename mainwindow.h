#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFont>
#include <QButtonGroup>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QSize>
#include <QGridLayout>
#include <QScrollBar>

class mainwindow: public QMainWindow {
    Q_OBJECT
private:
    QPushButton* ricerca;

public:
    mainwindow(QWidget* =nullptr);
    ~mainwindow() = default;
public slots:
    void schiacciaRicerca();
};

#endif // MAINWINDOW_H
