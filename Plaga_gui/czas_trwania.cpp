#include "czas_trwania.h"
#include "ui_czas_trwania.h"

czas_trwania::czas_trwania(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::czas_trwania)
{
    ui->setupUi(this);
}

czas_trwania::~czas_trwania()
{
    delete ui;
}

void czas_trwania::on_OK_clicked()
{
    data_konca.set(ui->spinBox_miesiac_koniec->value(),ui->spinBox_rok_koniec->value());
    this->close();
}
