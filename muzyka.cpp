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
        ui->progressBar->setValue(pos); //! ustawia wartość progress bara w
    });

    connect(Muzyczka, &QMediaPlayer::durationChanged, [&](qint64 dur){
        ui->progressBar->setMaximum(dur);
    });

    ui->lineEdit->setText("Projekt Pandemic OST");
}

muzyka::~muzyka()
{
    delete ui;
}

void muzyka::mute()
{
    Muzyczka->setMuted(true);
}

void muzyka::unmute()
{
    Muzyczka->setMuted(false);
}

void muzyka::startow()
{
    Muzyczka->setMedia(QUrl("qrc:/SFX/BG.mp3"));
    Muzyczka->setVolume(60);
    Muzyczka->play();
}

void muzyka::rewind()
{
    if(ui->lineEdit->text()=="Projekt Pandemic OST")
    if(Muzyczka->state()==QMediaPlayer::StoppedState)
    {
        Muzyczka->setPosition(0);
        Muzyczka->play();
    }
}

void muzyka::on_ButWybierz_clicked()
{
    Muzyczka->stop();
    QString plik_nazwa = QFileDialog::getOpenFileName(this, "Otwórz");
        if(plik_nazwa.isEmpty())
        {
            Muzyczka->setMedia(QUrl("qrc:/SFX/BG.mp3"));
            Muzyczka->play();
            return;
        }
        ui->lineEdit->setText(plik_nazwa);
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


