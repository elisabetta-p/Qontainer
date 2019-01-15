#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QObject>
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
#include <QAction>
#include <QScrollArea>

class mainwindow: public QMainWindow {
    Q_OBJECT
private:
    QPushButton* ricerca;
public:
    mainwindow(QWidget* =nullptr);
    ~mainwindow() = default;
private slots:
    void schiacciaRicerca();
    void schiacciaAggiungi();
};

#endif // MAINWINDOW_H
