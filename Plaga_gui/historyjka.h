#ifndef HISTORYJKA_H
#define HISTORYJKA_H
#include "symulacja.h"

#include <QDialog>
#include <QVector>
#include <QString>
#include <fstream>
#include <QImage>
#include <QPixmap>


namespace Ui {
class Historyjka;


}

class Historyjka : public QDialog
{
    Q_OBJECT

public:
    explicit Historyjka(QWidget *parent = 0);
    ~Historyjka();

    void dodaj_el(QString cos);

    void aktualizuj_lista();

    void wyswietl();

    void zapisz_do_pliku(QString do_zapisu);

    void odczyt_do_czegos();

    void usun_z(string do_usuniecia);

    void wyczysc();

    void czy_puste();

public slots:

signals:

private slots:

        void on_ButOpen_clicked();

        void on_ButDelete_clicked();

        void on_ButKill_clicked();


private:
    Ui::Historyjka *ui;

    QVector<QString> historia;
};

#endif // HISTORYJKA_H
