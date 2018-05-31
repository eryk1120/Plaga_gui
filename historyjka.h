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

    void dodaj_el(QString cos);  //! dodaje nowy element do wektora Qstring przechowującego nazwy obrazów mapy głównego interfejsu

    void aktualizuj_lista(); //! odczytuje wektor i aktualizuje listwidget o nowo dodane elementy

    void zapisz_do_pliku(QString do_zapisu); //! zapisuje w pliku elementu nazwy elemntów w celu będącymi ścieżkami do zpisanych obrazów

    void odczyt_do_czegos(); //!aktualizuje wektor o elementy zawarte w pliku historii

    void usun_z(string do_usuniecia); //! usuwa wybrane przez użytkownika elementy historii

    void wyczysc(); //! usuwa wszystkie elementy pliku Historia

    void czy_puste(); //!ustawia zalączanie przycisków w zależności od ilości elementów historii

public slots:

signals:

private slots:

        void on_ButOpen_clicked(); //! zalącza obraz będący elementem historii jako podgląd zapisanego efektu symulacji

        void on_ButDelete_clicked(); //!usuwa pojedynczy wybrany element historii

        void on_ButKill_clicked(); //!usuwa wszystkie elementy historii


private:
    Ui::Historyjka *ui;

    QVector<QString> historia; //!wektor przechowujący elementy
};

#endif // HISTORYJKA_H
