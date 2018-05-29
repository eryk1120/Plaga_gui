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

    void dodaj_strone(QImage stronka); //!dodaje element Qimage do wektora przechowującego strony instrukcji


public slots:

    void on_buttNext_clicked(); //!załącza kolejny element wektora będący kolejną strona instrukcji

    void on_Previous_clicked(); //!załącza poprzedni element wektora będący poprzednią stroną instrukcji

    void on_ButFull_clicked(); //!otwiera pełną instrukcję w formacie pdf

private:
    Ui::Instrukcja *ui;

    QVector <QImage> instrukcja; //!Wektor obrazów będących elementami stronami instrukcji


    QImage *strona1 = new QImage(":/IMG/Strona1.png");
    QImage *strona2 = new QImage(":/IMG/Strona2.png");
    QImage *strona3 = new QImage(":/IMG/Strona3.png");
    QImage *strona4 = new QImage(":/IMG/Strona4.png");
    QImage *strona5 = new QImage(":/IMG/Strona5.png");
};

#endif // INSTRUKCJA_H
