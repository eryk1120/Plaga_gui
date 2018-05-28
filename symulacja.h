#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <QString>

#include "lista.h"
#include "czas.h"

using namespace std;

class symulacja
{
private:

    struct Kraje{
        string nazwa;
        short int ratio = -1, old_ratio = -1;
        unsigned int ludnosc,  chorzy=0;
        unsigned int powierzchnia;
        unsigned int  gestosc;
        bool klimat;
        bool dos_morze;
        int health_care;
        int GNI;
        lista graniczy_z;  // jest lista bo mniejsza będzie o wiele
    };

    struct Choroby
    {
       string nazwa_choroby;
       int BRN;
       int czas;
       bool czy_pasozyt;
    };




     vector<Kraje>  world;
     vector<Choroby> virus;
     //czas start, aktualny, koniec;
     long long int infected=0, L_ludzi=0;
     lista lotne;

public:

     czas start, aktualny, koniec;

public:



     // konstrukcja

     symulacja();     
     ~symulacja();

     void reset();

     //pomocnicze konstruktora
     void dodaj_element(string nazwa_pliku);// tworzy wektor z krajami
     void dodaj_chorby(string nazwa_pliku);
     void czytaj_macierz (string NazwaPliku);// dodaje do gotowego wektora listy sąsiadów


     //zaraza
     void fala();
     void zaraza();
     void hit();
     void loty();
     bool czy_koniec();


     //utility
     bool czy_zmiana(int i);

     int size();
     int size2();

     void infect(int i,int liczba);

     int szukaj_indeks(string Nazwa);
     int szukaj_indeks(QString Nazwa);

     void set_data(int m, int r);
     void set_koniec(int m, int r);

     string dej_chorbe(int);
     string dej_nazwe(int);
     int dej_ludnosc(int i);
     int dej_chorzy(int i);
     int dej_powierzchnia(int i);
     int dej_ratio(int i);
     int dej_BRN(int i);
     int dej_czas(int i);

     double ustaw_b(int i);

};
#endif // VECTOR_H
