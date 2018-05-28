#ifndef OD_TWORCOW_H
#define OD_TWORCOW_H

#include <QDialog>
#include <QImage>
#include <QPixmap>

namespace Ui {
class Od_Tworcow;
}

class Od_Tworcow : public QDialog
{
    Q_OBJECT

public:
    explicit Od_Tworcow(QWidget *parent = 0);
    ~Od_Tworcow();

    void dodaj_strone(QImage stronka);

private slots:
    void on_previous_clicked();

    void on_next_clicked();

private:
    Ui::Od_Tworcow *ui;

    QVector <QImage> notatka;


    QImage *strona1 = new QImage(":/IMG/Od_Tworcow1.png");
    QImage *strona2 = new QImage(":/IMG/Od_Tworcow2.png");
    QImage *strona3 = new QImage(":/IMG/Od_Tworcow3.png");
};

#endif // OD_TWORCOW_H
