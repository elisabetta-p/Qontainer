#include "ricercaavanzata.h"
#include "ui_ricercaavanzata.h"

ricercaavanzata::ricercaavanzata(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ricercaavanzata)

{
    ui->setupUi(this);
    /* QLineEdit* lineEditTitolo = new QLineEdit(this);*/
    lineEditTitolo.setPlaceholderText("banana");
}

ricercaavanzata::~ricercaavanzata()
{
    delete ui;
}


