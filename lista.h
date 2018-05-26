#ifndef LISTA_H
#define LISTA_H
#include <iostream>

class lista
{
private:
    struct node      // struktura jednego węzłu listy,
    {
        node(int wartosc): indeks(wartosc), nast(nullptr){}    // to robi węzeł o podanej wartości (nr kraju) i wskaźniku na nic jak się tworzy nowe node

        int indeks;
        node * nast;

    };

public:
int dej(int N);
int jak_dluga();
void dodaj_element_po ( int );
void wypisz_liste ();
void usun_dowolny(int);
void usun_pierwszy();
bool czy_pusta();
void clean_list();
// bedzie jeszcze usuwanie elementów po idndeksie i jakimś sposobem żeby listy mogły się wymieniać elementami
// więcej metod chyba nie potrzeba, bo kolejność u nas nie gra roli. chyba, że destruktor bo nie wiem czy c++ jest na tyle mądry żeby sam dorze usuwał te listy, chwilowo czyści po nas windows bo program i

lista(): head(nullptr), ogon(nullptr) {}      // każdy obiekt 'lista' trzyma w sobie wskaźnik na swój ogon i głowę, później nich operuje latając po węzłach

private:
 node * head;
 node * ogon;

 //friend symulacja;

};


#endif // LISTA_H
