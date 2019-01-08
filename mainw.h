#ifndef MAINW_H
#define MAINW_H

#include <QWidget>

namespace Ui {
class mainw;
}

class mainw : public QWidget
{
    Q_OBJECT

public:
    explicit mainw(QWidget *parent = nullptr);
    ~mainw();

private:
    Ui::mainw *ui;
};

#endif // MAINW_H
