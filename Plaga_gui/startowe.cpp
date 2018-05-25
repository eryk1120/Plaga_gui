#include "startowe.h"
#include "ui_startowe.h"
#include <QMessageBox>

startowe::startowe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startowe)
{
    ui->setupUi(this);



    for(int i=0; i<54; i++)
    {
        ui->KrajeCombo->addItem(QString::fromStdString( world1->dej_nazwe(i)) );
    }

    for(int i=0; i<7; i++)
    {
        ui->combChoroba->addItem(QString::fromStdString( virus1->dej_chorbe(i)));   
    }

}

startowe::~startowe()
{
    delete ui;
}

void startowe::on_butt1_clicked()
{
    ui->KrajeCombo->clear();
    for(int i=0; i<54; i++)
    {
        ui->KrajeCombo->addItem(QString::fromStdString( world1->dej_nazwe(i)) );
    }
}

void startowe::on_butt2_clicked()
{
    ui->KrajeCombo->clear();
    for(int i=54; i<89; i++)
    {
        ui->KrajeCombo->addItem(QString::fromStdString( world1->dej_nazwe(i)) );
    }
}

void startowe::on_butt3_clicked()
{
    ui->KrajeCombo->clear();
    for(int i=89; i<103; i++)
    {
        ui->KrajeCombo->addItem(QString::fromStdString( world1->dej_nazwe(i)) );
    }
}

void startowe::on_butt4_clicked()
{
    ui->KrajeCombo->clear();
    for(int i=103; i<194; i++)
    {
        ui->KrajeCombo->addItem(QString::fromStdString( world1->dej_nazwe(i)) );
    }
}

void startowe::on_butt5_clicked()
{
    ui->combChoroba->clear();
    for(int i=0; i<7; i++)
        ui->combChoroba->addItem(QString::fromStdString( virus1->dej_chorbe(i)));
    ui->obraz_choroba->clear();
    ui->obraz_choroba->setPixmap(QPixmap::fromImage(*wirus));
}

void startowe::on_butt6_clicked()
{
    ui->combChoroba->clear();
    for(int i=7; i<13; i++)
        ui->combChoroba->addItem(QString::fromStdString( virus1->dej_chorbe(i)));
    ui->obraz_choroba->clear();
    ui->obraz_choroba->setPixmap(QPixmap::fromImage(*bakteria));
}

void startowe::on_butt7_clicked()
{
    ui->combChoroba->clear();
    for(int i=13; i<17; i++)
        ui->combChoroba->addItem(QString::fromStdString( virus1->dej_chorbe(i)));
    ui->obraz_choroba->clear();
    ui->obraz_choroba->setPixmap(QPixmap::fromImage(*pasozyt));
}

void startowe::on_try_2_clicked()
{
    this->close();



    QString text = " Zarażono: " + (ui->KrajeCombo->currentText()) +
    "\n Chorobą: "+ (ui->combChoroba->currentText()) +"\n Dnia: " + QString::number(ui->spinBoxMiesiac->value()) + "."
            + QString::number(ui->spinBoxRok->value());
    this->nazwa=ui->KrajeCombo->currentText();
    this->m=ui->spinBoxMiesiac->value();
    this->r=ui->spinBoxRok->value();



    QMessageBox::information(this,"THE FINAL PYTANKO",text);

    this->close();

}


void end_them()
{

}



