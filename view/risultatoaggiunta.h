#ifndef RISULTATOAGGIUNTA_H
#define RISULTATOAGGIUNTA_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QBoxLayout>


class risultatoaggiunta: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QGridLayout* griglia;
public:
    risultatoaggiunta(QWidget* = nullptr);
    ~risultatoaggiunta() = default;
};

#endif // RISULTATOAGGIUNTA_H
