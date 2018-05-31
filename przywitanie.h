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

    void odczyt(); //! sprawdza wartość pliku textowego aby wyświetlić powitanie przy pierwszym odpaleniu programu

private slots:
    void on_ButStart_clicked(); //!włącza główny interfejs symulatora

    void on_ButInst_clicked(); //!odpala instrukcję pdf

    void on_pushButton_clicked(); //!włącza okno z informacjami od twórców

private:
    Ui::Przywitanie *ui;

    Od_Tworcow odd;

    QImage *menu = new QImage(":/IMG/MENU.png");
    QMediaPlayer *back;
};

#endif // PRZYWITANIE_H
