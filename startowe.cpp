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



/*
void startowe::on_OKEJKA_accepted()
{
    QString text = "pandemia rozpocznie się w " + (ui->KrajeCombo->currentText()) +
    "z datą " + QString::number(ui->spinBoxMiesiac->value()) + "."
            + QString::number(ui->spinBoxRok->value());

    startowe * ptr= this;

    int x = QMessageBox::question(this,"THE FINAL PYTANKO",text);

    if(!x)
    {

    }
}
*/
void startowe::on_try_2_clicked()
{
    this->close();



    QString text = "zarażono " + (ui->KrajeCombo->currentText()) +
    "z datą " + QString::number(ui->spinBoxMiesiac->value()) + "."
            + QString::number(ui->spinBoxRok->value());
// musisz zrobić zmienne r_k i m_k i do nich zwrócić datę końca
    // jak chce ci się ogarniać signal-sloty to możesz zrobić zabezpieczenie żeby nie dało daty zakończenia przed startem
    // jak nie to potem to zroibę ( ui_>sinbox-> val  <  ui_>sinbox koncowy-> val
    this->nazwa=ui->KrajeCombo->currentText();
    this->m=ui->spinBoxMiesiac->value();
    this->r=ui->spinBoxRok->value();



    QMessageBox::information(this,"THE FINAL PYTANKO",text);

    this->close();

}
void end_them()
{

}



