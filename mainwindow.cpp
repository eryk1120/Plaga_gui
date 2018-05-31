#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "historyjka.h"

#include "symulacja.h"

#include <QPixmap>
#include <QColor>
#include<QDate>
#include<QTime>
#include <QDesktopServices>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    ofstream plik("Historia.txt");
    plik.close();
    ui->MAPKA->setPixmap(QPixmap::fromImage(*mapa));


    QDate data = QDate::currentDate();
    ui->curr_date->setText(data.toString(Qt::SystemLocaleDate));


    przyw.setModal(true);
    przyw.exec();


    muz.startow();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_start_clicked()
{
    muz.rewind();
    startowe *start = new startowe;
    start->setModal(true);
    start->exec();
    this->world.infect(world.szukaj_indeks(start->nazwa),20);
    this->world.set_data(start->m,start->r);
    ui->killEM->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->push_to_the_end->setEnabled(true);
    this->change_color(world.szukaj_indeks(start->nazwa),0);
}



void MainWindow::change_color(int indeks, short int procent)
{
    if(world.dej_chorzy(indeks)==0)
        return;

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

        change_color(i,world.dej_chorzy(i) / world.dej_ludnosc(i));
    }
}
void MainWindow::update_color_abs()
{
    for (int i=0;i<world.size();i++)
    {
        change_color(i,world.dej_ratio(i));
    }
}



void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    ui->xPosSpinBox->setValue(ev->x());
    ui->yPosSpinBox->setValue(ev->y());
    QWidget:: mousePressEvent(ev);

    int x=ui->xPosSpinBox->value();
    int y=ui->yPosSpinBox->value();
    QColor clrCurrent(matryca->pixel(x,y));

    int b=clrCurrent.blue();
    int L=world.dej_ludnosc(b-1);
    int C=world.dej_chorzy(b-1);
    int P=world.dej_powierzchnia(b-1);

    string f=world.dej_nazwe(b-1);
    ui->Nazwa->setText(QString::fromStdString(f));
    ui->Ludnosc->setText(QString::number(L));
    ui->Chorzy->setText(QString::number(C));
    ui->Powierzchnia->setText(QString::number(P));



}

QString MainWindow::zapisywanie()
{
    QDate data = QDate::currentDate();
    QTime czas = QTime::currentTime();
    QString prefiks = data.toString(Qt::SystemLocaleDate);
    QString sufiks = czas.toString();
    prefiks += "-";
    prefiks += sufiks;
    prefiks += ".png";

    for(int i=0; i<prefiks.size(); i++)
    {
        if(prefiks[i]==':')
            prefiks[i] = '-';
    }

    ui->MAPKA->grab().save(prefiks);
    QString text="Zapisano jako: "+ prefiks;
    QMessageBox::information(this,"O Zapisie", text);
    return prefiks;
}


void MainWindow::end_them()
{

    while(!world.czy_koniec())
    {
        world.fala();
    }
    this->update_color();
}

void MainWindow::on_killEM_clicked()
{
    muz.rewind();
    while(!world.czy_koniec())
    {
        world.fala();
    }
    this->update_color_abs();
    if(ui->checkBox->isChecked())
    {
        QString do_zapisu=zapisywanie();
        hist.dodaj_el(do_zapisu);
        hist.zapisz_do_pliku(do_zapisu);
    }
}



void MainWindow::on_push_to_the_end_clicked()
{
    muz.rewind();
    data_k_wybor * final = new data_k_wybor;
    final->startowe=world.start;
    final->set_up();
    final->setModal(true);
    final->exec();

    ui->spinBox_okrazenia->setValue(abs(final->startowe.odstep_miedzy(final->koncowe)));

    ui->pushButton->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    muz.rewind();
    for (int i=0 ; i < ui->spinBox_okrazenia->value() ; i++)
    {
        world.fala();
    }
    this->update_color_abs();
    if(ui->checkBox->isChecked())
    {
        QString do_zapisu=zapisywanie();
        hist.dodaj_el(do_zapisu);
        hist.zapisz_do_pliku(do_zapisu);
    }

}

void MainWindow::on_Help_clicked()
{
    muz.rewind();
    inst.setModal(true);
    inst.exec();
}

void MainWindow::on_pushSave_clicked()
{
    muz.rewind();
    QString do_zapisu = zapisywanie();
    hist.dodaj_el(do_zapisu);
    hist.zapisz_do_pliku(do_zapisu);
}

void MainWindow::on_PushHistoria_clicked()
{
    muz.rewind();
    hist.aktualizuj_lista();
    hist.setModal(true);
    hist.exec();

}


void MainWindow::on_ButMuzyka_clicked()
{
    muz.rewind();
    muz.setModal(true);
    muz.exec();
}

void MainWindow::on_ButMute_clicked()
{
    if(ui->ButMute->text() == "Mute")
    {
        muz.mute();
        ui->ButMute->setText("Unmute");
    }
    else
    {
        muz.unmute();
        ui->ButMute->setText("Mute");
    }
}

void MainWindow::on_ButReset_clicked()
{
    muz.rewind();
    world.reset();
    mapa = new QImage(":/IMG/Mapa.png");
    ui->MAPKA->setPixmap(QPixmap::fromImage(*mapa));
}
