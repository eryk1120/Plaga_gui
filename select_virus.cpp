#include "select_virus.h"
#include "ui_select_virus.h"

select_virus::select_virus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::select_virus)
{
    ui->setupUi(this);
}

select_virus::~select_virus()
{
    delete ui;
}


