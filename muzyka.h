#ifndef MUZYKA_H
#define MUZYKA_H

#include <QDialog>

namespace Ui {
class muzyka;
}

class QMediaPlayer;

class muzyka : public QDialog
{
    Q_OBJECT

public:
    explicit muzyka(QWidget *parent = 0);
    ~muzyka();

private slots:
    void on_ButWybierz_clicked();

    void on_ButGraj_clicked();

    void on_ButPausa_clicked();

    void on_ButStop_clicked();

    void on_horizontalSlider_valueChanged(int value);


private:
    Ui::muzyka *ui;
    QMediaPlayer *Muzyczka;
};

#endif // MUZYKA_H
