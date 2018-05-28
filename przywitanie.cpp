#include "przywitanie.h"
#include "ui_przywitanie.h"
#include "instrukcja.h"
#include "symulacja.h"
#include "muzyka.h"

#include <QDesktopServices>
#include <QtGui>
#include <QUrl>
#include <QMessageBox>
#include <QMediaPlayer>

Przywitanie::Przywitanie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Przywitanie)
{
    ui->setupUi(this);
    ui->Przywitanie_2->setPixmap(QPixmap::fromImage(*menu));
    odczyt();

}

Przywitanie::~Przywitanie()
{
    delete ui;
}

void Przywitanie::odczyt()
{
    ifstream plik("Pierwsze_odpalenie.txt");
    int i;
    plik>>i;
    plik.close();
    if(i==1)
    {
        QMessageBox::information(this,"Przywitanie","Witamy w \"Projekt Pandemic\" \n Przed rozpoczęciem pracy z programem zalecamy zapozać się z instrukcją użytkowania dołączoną do programu \nPowodzenia !!");
        ofstream nowy("Pierwsze_odpalenie.txt");
        i=0;
        nowy<<i;
        nowy.close();
    }
    if(i==0)
        return;
}

void Przywitanie::on_ButStart_clicked()
{
    this->close();
}

void Przywitanie::on_ButInst_clicked()
{
    QDesktopServices::openUrl(QUrl("Instrukcja.pdf"));
}

void Przywitanie::on_pushButton_clicked()
{
    odd.setModal(true);
    odd.exec();
}
