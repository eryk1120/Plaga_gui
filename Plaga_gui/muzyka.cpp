#include "muzyka.h"
#include "ui_muzyka.h"

#include <QMediaPlayer>
#include <QFileDialog>

muzyka::muzyka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::muzyka)
{
    ui->setupUi(this);
    Muzyczka = new QMediaPlayer(this);

    connect(Muzyczka, &QMediaPlayer::positionChanged, [&](qint64 pos){
        ui->progressBar->setValue(pos);
    });

    connect(Muzyczka, &QMediaPlayer::durationChanged, [&](qint64 dur){
        ui->progressBar->setMaximum(dur);
    });
}

muzyka::~muzyka()
{
    delete ui;
}

void muzyka::on_ButWybierz_clicked()
{
    Muzyczka->stop();
    QString plik_nazwa = QFileDialog::getOpenFileName(this, "Otwórz");
        if(plik_nazwa.isEmpty())
            return;
        Muzyczka->setMedia(QUrl::fromLocalFile(plik_nazwa));
        Muzyczka->setVolume(0);
        on_ButGraj_clicked();
}

void muzyka::on_ButGraj_clicked()
{
    Muzyczka->play();
}


void muzyka::on_ButPausa_clicked()
{
    Muzyczka->pause();
}

void muzyka::on_ButStop_clicked()
{
    Muzyczka->stop();
}

void muzyka::on_horizontalSlider_valueChanged(int value)
{
    int i = ui->horizontalSlider->value();
    ui->label_2->setText(QString::number(i));
    Muzyczka->setVolume(i);
}


