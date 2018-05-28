#ifndef PRZYWITANIE_H
#define PRZYWITANIE_H

#include "od_tworcow.h"

#include <QDialog>
#include <QImage>
#include <QPixmap>
#include <QMediaPlayer>


namespace Ui {
class Przywitanie;
}

class Przywitanie : public QDialog
{
    Q_OBJECT

public:
    explicit Przywitanie(QWidget *parent = 0);
    ~Przywitanie();

    void odczyt();

private slots:
    void on_ButStart_clicked();

    void on_ButInst_clicked();

    void on_pushButton_clicked();

private:
    Ui::Przywitanie *ui;

    Od_Tworcow odd;

    QImage *menu = new QImage(":/IMG/MENU.png");
    QMediaPlayer *back;
};

#endif // PRZYWITANIE_H
