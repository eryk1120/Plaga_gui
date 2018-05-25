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
    void setlabel(QString);
    void change_color(int indeks,short int procent);
    void end_them();
    void update_color ();
    void update_color_abs ();
    void odczytaj_plik();

public slots:

protected:
    void mousePressEvent(QMouseEvent *ev) override;

        QString zapisywanie();

private slots:
    void on_start_clicked();

    void on_killEM_clicked();

    void on_push_to_the_end_clicked();

    void on_pushButton_clicked();

    void on_Help_clicked();

    void on_pushSave_clicked();

    void on_PushHistoria_clicked();


    void on_ButMuzyka_clicked();

private:
    Ui::MainWindow *ui;
    symulacja world;
    symulacja virus;
    Historyjka hist;
    Instrukcja inst;
    Przywitanie przyw;
    muzyka muz;


public:
    QImage * matryca = new QImage(":/IMG/matryca.png");
    QImage * mapa = new QImage(":/IMG/Mapa.png");



};

#endif // MAINWINDOW_H
