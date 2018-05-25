#include "historyjka.h"
#include "ui_historyjka.h"
#include "symulacja.h"


#include<QImage>
#include<QPixmap>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<fstream>
#include<QtGui>

Historyjka::Historyjka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Historyjka)
 {
    odczyt_do_czegos();
    ui->setupUi(this);
}

Historyjka::~Historyjka()
{
    delete ui;
}

void Historyjka::dodaj_el(QString cos)
{
    historia.push_front(cos);
}

void Historyjka::aktualizuj_lista()
{
    ui->Wybor_lista->clear();
    for(int i=0; i<historia.size(); i++)
    {
        ui->Wybor_lista->addItem(historia[i]);
    }
    czy_puste();
}

void Historyjka::zapisz_do_pliku(QString do_zapisu)
{
    QFile plik("Historia.txt");
    plik.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream out(&plik);
    do_zapisu+="\r\n";
    out<<do_zapisu;
    plik.close();
}

void Historyjka::odczyt_do_czegos()
{
    QFile plik("Historia.txt");
    plik.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&plik);
    QString linijka;

    while(!in.atEnd())
    {
        linijka = in.readLine();
        historia<<linijka;

    }
    plik.close();
}

void Historyjka::usun_z(string do_usuniecia)
{
 string linijka;
 ifstream plik("Historia.txt");
 ofstream temp("Temp.txt");

 while( getline(plik, linijka))
 {
     if(linijka != do_usuniecia)
     {
         linijka+="\n";
         temp<<linijka;
     }
     temp.close();
     plik.close();

     const char *p = "Historia.txt";
     remove(p);
     rename("Temp.txt",p);

 }


}

void Historyjka::wyczysc()
{
    ofstream plik("Historia.txt");
    plik.close();
}

void Historyjka::czy_puste()
{
 int i=ui->Wybor_lista->count();

 if(i==0)
 {
     ui->ButDelete->setDisabled(true);
     ui->ButKill->setDisabled(true);
 }
 if(i>0 && i<3)
 {
     ui->ButDelete->setEnabled(true);
     ui->ButKill->setDisabled(true);
 }
 if(i>=3)
 {
     ui->ButKill->setEnabled(true);
     ui->ButDelete->setEnabled(true );
 }

}

void Historyjka::on_ButOpen_clicked()
{
    ui->podglad->clear();
    QString obraz = ui->Wybor_lista->currentItem()->text();
    QImage bla(obraz);
    QImage obraz2 = bla.scaled(600,340,Qt::KeepAspectRatio);

    ui->podglad->setPixmap(QPixmap::fromImage(obraz2));

}

void Historyjka::on_ButDelete_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Usuń","Czy na pewno chcesz usunać ten plik ?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::No)
        return;

    if(reply == QMessageBox::Yes)
    {

    QListWidgetItem *itm = ui->Wybor_lista->currentItem();
    ui->Wybor_lista->removeItemWidget(itm);
    QString tmp=ui->Wybor_lista->currentItem()->text();
    string tmp2=ui->Wybor_lista->currentItem()->text().toStdString();

    QFile file(tmp);
    file.remove();

    usun_z(tmp2);
    for(int i=0; i<historia.size(); i++)
    {
        if(historia[i]==tmp)
            historia.remove(i);
    }
    ui->podglad->clear();
    delete itm;
    czy_puste();
    }
}

void Historyjka::on_ButKill_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Usuń Wszytskie","Czy na pewno chcesz wyczyścić historię ?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No)
        return;
    if(reply == QMessageBox::Yes)
    {
   ui->Wybor_lista->clear();
   for(int i=0; i<historia.size();i++)
   {
       QString tmp = historia[i];
       QFile file(tmp);
       file.remove();
   }
   historia.clear();
   ui->podglad->clear();
   wyczysc();
   ui->ButDelete->setDisabled(true);
   ui->ButKill->setDisabled(true);
}
}









