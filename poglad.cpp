#include "poglad.h"
#include "ui_poglad.h"

Poglad::Poglad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poglad)
{
    ui->setupUi(this);
}

Poglad::~Poglad()
{
    delete ui;
}
