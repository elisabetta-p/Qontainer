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

class mainwindow: public QWidget {
    Q_OBJECT
private:
    QPushButton* ricerca;
    QVBoxLayout* layout;
    QHBoxLayout* boxBottoni;
    QGridLayout* griglia;
public:
    mainwindow(QWidget* =nullptr);
    ~mainwindow() = default;

};

#endif // MAINWINDOW_H
