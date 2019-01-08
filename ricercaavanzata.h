#ifndef RICERCAAVANZATA_H
#define RICERCAAVANZATA_H

#include <QWidget>
#include <QLineEdit>

namespace Ui {
class ricercaavanzata;
}

class ricercaavanzata : public QWidget
{
    Q_OBJECT

public:
    explicit ricercaavanzata(QWidget *parent = nullptr);
    ~ricercaavanzata();

private slots:
    void on_lineEditTitolo_textEdited(const QString &arg1);

    void on_lineEditTitolo_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::ricercaavanzata *ui;
    QLineEdit lineEditTitolo, lineEditAutore, lineEditDurata, lineEditGenere, lineEditAnno;
};

#endif // RICERCAAVANZATA_H
