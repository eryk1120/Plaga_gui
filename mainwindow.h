#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "symulacja.h"
#include "lista.h"
#include "startowe.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QImage>


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

public slots:



private slots:
    void on_start_clicked();



    void on_killEM_clicked();

private:
    Ui::MainWindow *ui;
    symulacja world;
public:
    QImage * matryca = new QImage(":/IMG/matryca.png");
    QImage * mapa = new QImage(":/IMG/Mapa.png");


};

#endif // MAINWINDOW_H
