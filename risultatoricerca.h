#ifndef RISULTATORICERCA_H
#define RISULTATORICERCA_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>


class risultatoricerca: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QGridLayout* griglia;
public:
    risultatoricerca(QWidget* = nullptr);
    ~risultatoricerca() = default;
};

#endif // RISULTATORICERCA_H
