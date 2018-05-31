#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "symulacja.h"
#include "lista.h"
#include "startowe.h"
#include "czas.h"
#include "select_virus.h"
#include "czas_trwania.h"
#include <historyjka.h>
#include "data_k_wybor.h"
#include "instrukcja.h"
#include "przywitanie.h"
#include "muzyka.h"


#include <QMainWindow>
#include <QMessageBox>
#include <QImage>
#include <QMouseEvent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /*!
     * \brief change_color
     * aktualizuje kolor danego państwa na mapie
     * \param indeks
     * indeks państwa
     * \param procent
     * % zarażenia
     */
    void change_color(int indeks,short int procent);
    /*!
     * \brief end_them
     * metoda działająca do zarażenia całego świata
     */
    void end_them();
    /*!
     * \brief update_color
     * akualizuje kolor całego świata
     */
    void update_color ();
    /*!
     * \brief update_color_abs
     * aktualizuje kolor całego świata
     */
    void update_color_abs ();


public slots:

protected:
    void mousePressEvent(QMouseEvent *ev) override; //! funkcja odbiera od systemu aktulną pozycję wskaźnieka myszki we współrzędnych pikselowych po czym odczytuje barwę danego pola w barwch qRGB, odnajduje indeks odpowiadającego mu państwa i wyświetla dane w oknie informacyjnym

        QString zapisywanie(); //!funkcja zapisuje obraz mapy głównego ingterfejsu wykorzystując do tego aktlany czas systemu komputera w formacie "data-godzina".png

private slots:
    void on_start_clicked();

    void on_killEM_clicked();

    void on_push_to_the_end_clicked();

    void on_pushButton_clicked();

    void on_Help_clicked();

    void on_pushSave_clicked();

    void on_PushHistoria_clicked();


    void on_ButMuzyka_clicked();

    void on_ButMute_clicked();


    void on_ButReset_clicked();

private:

    Ui::MainWindow *ui;
    /*!
     * \brief world
     * obiekt symulacji
     *
     */
    symulacja world;
    symulacja virus;
    Historyjka hist;
    Instrukcja inst;
    Przywitanie przyw;
    muzyka muz;


public:
    /*!
     * \brief matryca
     * zdjęcie z którego program odczytuje miejsce w którym leży państwo
     */
    QImage * matryca = new QImage(":/IMG/matryca.png");
    /*!
     * \brief mapa
     * zdjęcie wyświetlane użytkownikowi i zmieniane w czasie
     */
    QImage * mapa = new QImage(":/IMG/Mapa.png");

    QMediaPlayer *muza = new QMediaPlayer();

};

#endif // MAINWINDOW_H
