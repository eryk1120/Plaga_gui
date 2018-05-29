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

    void mute(); //!wycisza zalączoną muzyke

    void unmute(); //!ponownie włącza dźwięk muzyki

    void startow(); //!zalącza oryginalna muzykę tła dla symulacji

    void rewind();//!przewija i ponownie odtwarza muzykę

private slots:
    void on_ButWybierz_clicked(); //! pozwala użytkownikowi wybrać plik mp3 do odpalenia w odtwarzaczu

    void on_ButGraj_clicked(); //!odpala załączoną przez urzytkownika muzykę

    void on_ButPausa_clicked(); //!zatrzymuje odpaloną muzykę

    void on_ButStop_clicked(); //!anuluje odpaloną muzykę

    void on_horizontalSlider_valueChanged(int value); //!ustawia głosność muzyki w zależności od wartości slidera


private:
    Ui::muzyka *ui;
    QMediaPlayer *Muzyczka;
};

#endif // MUZYKA_H
