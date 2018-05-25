#include "instrukcja.h"
#include "ui_instrukcja.h"

#include <QtGui>
#include <QSpinBox>
#include <QDesktopServices>


Instrukcja::Instrukcja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Instrukcja)
{
    ui->setupUi(this);
    dodaj_strone(*strona1);
    dodaj_strone(*strona2);
    dodaj_strone(*strona3);
    dodaj_strone(*strona4);
    dodaj_strone(*strona5);

    ui->spinBox->setValue(1);
    ui->Instrukcja_widok->setPixmap(QPixmap::fromImage(instrukcja[ui->spinBox->value()-1]));


}

Instrukcja::~Instrukcja()
{
    delete ui;
}

void Instrukcja::dodaj_strone(QImage stronka)
{
    instrukcja.push_back(stronka);
}

void Instrukcja::on_buttNext_clicked()
{
    if(ui->spinBox->value()<5)
        ui->spinBox->setValue(ui->spinBox->value()+1);

    ui->Instrukcja_widok->clear();
    ui->Instrukcja_widok->setPixmap(QPixmap::fromImage(instrukcja[ui->spinBox->value()-1]));
}

void Instrukcja::on_Previous_clicked()
{
    if(ui->spinBox->value()>0)
        ui->spinBox->setValue(ui->spinBox->value()-1);

    ui->Instrukcja_widok->clear();
    ui->Instrukcja_widok->setPixmap(QPixmap::fromImage(instrukcja[ui->spinBox->value()-1]));
}

void Instrukcja::on_ButFull_clicked()
{
    QDesktopServices::openUrl(QUrl("Instrukcja.pdf"));
}
