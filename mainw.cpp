#include "mainw.h"
#include "ui_mainw.h"

mainw::mainw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainw)
{
    ui->setupUi(this);
}

mainw::~mainw()
{
    delete ui;
}
