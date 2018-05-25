#include "data_k_wybor.h"
#include "ui_data_k_wybor.h"

data_k_wybor::data_k_wybor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::data_k_wybor)
{
    ui->setupUi(this);
}

data_k_wybor::~data_k_wybor()
{
    delete ui;
}

void data_k_wybor::set_up()
{
    ui->spinBox_rok_2->setMinimum(this->startowe.rok+1);
    ui->spinBox_rok_2->setMaximum(this->startowe.rok+51);

}

void data_k_wybor::on_ook_clicked()
{
    koncowe.set(ui->spinBox_miesiac->value(),ui->spinBox_rok_2->value());
    this->close();
}
