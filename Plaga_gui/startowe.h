#ifndef STARTOWE_H
#define STARTOWE_H

#include "mainwindow.h"
#include "lista.h"
#include "startowe.h"

#include <QDialog>

namespace Ui {
class startowe;
}

class startowe : public QDialog
{
    Q_OBJECT

public:
    explicit startowe(QWidget *parent = 0);
    ~startowe();

private slots:
    void on_butt1_clicked();

    void on_butt2_clicked();

    void on_butt3_clicked();

    void on_butt4_clicked();

    void on_butt5_clicked();

    void on_butt6_clicked();

    void on_butt7_clicked();

    void on_try_2_clicked();




signals:
    void end_it();

private:
    Ui::startowe *ui;
    symulacja * world1 = new symulacja ();
    symulacja * virus1 = new symulacja ();
public:
    QString nazwa;
    int m,r, mk, rk;

    QImage * wirus = new QImage(":/IMG/Wirus.png");
    QImage * bakteria = new QImage(":/IMG/Bakteria.png");
    QImage * pasozyt = new QImage(":/IMG/Pasozyt.png");


};

#endif // STARTOWE_H



