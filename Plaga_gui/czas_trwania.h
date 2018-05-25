#ifndef CZAS_TRWANIA_H
#define CZAS_TRWANIA_H

#include <QWidget>

#include "czas.h"
namespace Ui {
class czas_trwania;
}

class czas_trwania : public QWidget
{
    Q_OBJECT

public:
    explicit czas_trwania(QWidget *parent = 0);
    ~czas_trwania();

private slots:
    void on_OK_clicked();

private:
    Ui::czas_trwania *ui;
    czas data_konca;
};

#endif // CZAS_TRWANIA_H
