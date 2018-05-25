#ifndef DATA_K_WYBOR_H
#define DATA_K_WYBOR_H

#include <QDialog>

#include "czas.h"

namespace Ui {
class data_k_wybor;
}

class data_k_wybor : public QDialog
{
    Q_OBJECT

public:
    explicit data_k_wybor(QWidget *parent = 0);
    ~data_k_wybor();
    czas startowe,koncowe;
    void set_up();

private slots:
    void on_ook_clicked();

private:
    Ui::data_k_wybor *ui;

};

#endif // DATA_K_WYBOR_H
