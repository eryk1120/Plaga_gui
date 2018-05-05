#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "symulacja.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);


    ui->MAPKA->setPixmap(QPixmap::fromImage(*mapa));

    ui->test_label->setText(QString::number(world.size()));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_start_clicked()
{
    startowe *start = new startowe;
    start->setModal(true);
    start->exec();
    ui->test_label->setText("DUPA");
    ui->test_label->setText(start->nazwa);
    this->world.infect(world.szukaj_indeks(start->nazwa),20);
    this->world.set_data(start->m,start->r);
    ui->killEM->setEnabled(true);
    ui->test_label->setText(QString::number( world.szukaj_indeks(start->nazwa)));
    this->change_color(world.szukaj_indeks(start->nazwa),0);


}

void MainWindow::setlabel(QString x)
{
    ui->test_label->setText(x);
}
/*
void MainWindow::get_obj(QString nazwa, int m, int r)
{
    QMessageBox::about(this,"fuck","you");
    ui->test_label->setText("done");
    world.infect(world.szukaj_indeks(nazwa),10);
    world.set_data(m,r);
    ui->test_label->setText("done");
}
*/

void MainWindow::change_color(int indeks, short int procent)
{
    for (int i=0; i < matryca->width(); i++)
    {
        for (int j=0; j < matryca->height(); j++)
        {
            if(matryca->pixel(i,j) == qRgb(0,0,indeks+1))
            {
                if(procent<=50)
                {
                    mapa->setPixel(i,j, qRgb(5*procent,250,0));
                }
                else if(procent>50)
                {
                    mapa->setPixel(i,j, qRgb(250,250-5*(procent-50),0));
                }
            }
        }
    }
    ui->MAPKA->setPixmap(QPixmap::fromImage(*mapa));
}
void MainWindow::update_color()
{
    for (int i=0;i<world.size();i++)
    {
        if (world.czy_zmiana(i))
            change_color(i,world.dej_ratio(i));
    }
}

void MainWindow::end_them()
{
    while(!world.czy_koniec())
    {
        world.fala();
        this->update_color();

    }

}

void MainWindow::on_killEM_clicked()
{
    ui->test_label->setText("wow");
    this->end_them();
    this->update_color();
}
