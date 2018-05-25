#ifndef INSTRUKCJA_H
#define INSTRUKCJA_H

#include <QDialog>
#include <QVector>
#include <QImage>

namespace Ui {
class Instrukcja;
}

class Instrukcja : public QDialog
{
    Q_OBJECT

public:
    explicit Instrukcja(QWidget *parent = 0);
    ~Instrukcja();

    void dodaj_strone(QImage stronka);

    int m=1;

public slots:

    void on_buttNext_clicked();

    void on_Previous_clicked();

    void on_ButFull_clicked();

private:
    Ui::Instrukcja *ui;

    QVector <QImage> instrukcja;


    QImage *strona1 = new QImage(":/IMG/Strona1.png");
    QImage *strona2 = new QImage(":/IMG/Strona2.png");
    QImage *strona3 = new QImage(":/IMG/Strona3.png");
    QImage *strona4 = new QImage(":/IMG/Strona4.png");
    QImage *strona5 = new QImage(":/IMG/Strona5.png");
};

#endif // INSTRUKCJA_H
