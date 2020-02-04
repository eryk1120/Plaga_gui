#include "mainwindow.h"
#include "startowe.h"

#include "symulacja.h"
#include "lista.h"

#include <QApplication>
#include <QImage>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    w.show();


    return a.exec();
}
