#include "od_tworcow.h"
#include "ui_od_tworcow.h"

Od_Tworcow::Od_Tworcow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Od_Tworcow)
{
    ui->setupUi(this);
    dodaj_strone(*strona1);
    dodaj_strone(*strona2);
    dodaj_strone(*strona3);

    ui->spinBox->setValue(1);
    ui->label->setPixmap(QPixmap::fromImage(notatka[ui->spinBox->value()-1]));

}

Od_Tworcow::~Od_Tworcow()
{
    delete ui;
}

void Od_Tworcow::dodaj_strone(QImage stronka)
{
    notatka.push_back(stronka);
}

void Od_Tworcow::on_previous_clicked()
{
    if(ui->spinBox->value()>0)
        ui->spinBox->setValue(ui->spinBox->value()-1);

    ui->label->clear();
    ui->label->setPixmap(QPixmap::fromImage(notatka[ui->spinBox->value()-1]));

}

void Od_Tworcow::on_next_clicked()
{
    if(ui->spinBox->value()<3)
        ui->spinBox->setValue(ui->spinBox->value()+1);

    ui->label->clear();
    ui->label->setPixmap(QPixmap::fromImage(notatka[ui->spinBox->value()-1]));
}
