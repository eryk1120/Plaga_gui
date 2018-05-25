#ifndef SELECT_VIRUS_H
#define SELECT_VIRUS_H

#include <QDialog>

namespace Ui {
class select_virus;
}

class select_virus : public QDialog
{
    Q_OBJECT

public:
    explicit select_virus(QWidget *parent = 0);
    ~select_virus();

private slots:


private:
    Ui::select_virus *ui;
};

#endif // SELECT_VIRUS_H
