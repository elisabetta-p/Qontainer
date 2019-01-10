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


class mainwindow: public QMainWindow {
    Q_OBJECT
private:
    void creaTitolo();
    void creaBottoni();
    void creaListeContenuti();
    QGroupBox gruppoBottoni;
    QPushButton* bottoni[2];
    /*
    QLabel* titoloFinestra, *lib, *artisti, *film, *serie, *podcast;
    QPushButton *ricerca, *aggiungi;
    QVBoxLayout *layoutArtisti, *layoutFilm, *layoutSerie, *layoutPodcast;
    */
public:
    mainwindow(QWidget* =nullptr);
    // mainwindow(QLabel, QPushButton, QPushButton, QLabel, QLabel,QLabel,QLabel,QLabel, QVBoxLayout, QVBoxLayout, QVBoxLayout, QVBoxLayout);
    ~mainwindow() = default;
};

#endif // MAINWINDOW_H
