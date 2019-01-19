#ifndef RISULTATORICERCA_H
#define RISULTATORICERCA_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>


class risultatoricerca: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layout;
public:
    risultatoricerca(QWidget* = nullptr);
    ~risultatoricerca() = default;
};

#endif // RISULTATORICERCA_H
