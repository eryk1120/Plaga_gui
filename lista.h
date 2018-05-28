#ifndef LISTA_H
#define LISTA_H
#include <iostream>
/*!
 * \brief The lista class
 * klasa listy jednokierunkowej zawierającej dane typu int
 */
class lista
{
private:
    /*!
     * \brief The node struct
     * struktura pojedyńczego węzła listy
     */
    struct node      // struktura jednego węzłu listy,
    {
        /*!
         * \brief node
         * konstruktor węzła listy o podanej wartości
         * \param wartosc
         * wartość
         */
        node(int wartosc): indeks(wartosc), nast(nullptr){}    // to robi węzeł o podanej wartości (nr kraju) i wskaźniku na nic jak się tworzy nowe node
        /*!
         * \brief indeks
         * zmienna zawierająca liczbę w węźle
         */
        int indeks;
        /*!
         * \brief nast
         * wskaźnik na następny element
         */
        node * nast;

    };

public:
    /*!
 * \brief dej
 * funkcja zwracająca wskazany element (n'ty z listy)
 * \param N
 * indeks zwracanego elementu
 * \return wartość węzła
 */
int dej(int N);
/*!
 * \brief jak_dluga
 * metoda zwracająca ilość elementów w liście
 * \return l. węzłów
 */
int jak_dluga();
/*!
 * \brief dodaj_element_po
 * dodaje węzeł na n+1 miejscu
 * \param n
 *
 */
void dodaj_element_po ( int n );
/*!
 * \brief wypisz_liste
 * metoda wypisująca listę
 * \warning używana dla aplikacji konsolowej
 */
void wypisz_liste ();
/*!
 * \brief usun_dowolny
 * usuwa n'ty element listy
 * \param n
 * numer elementu do usunięcia
 */
void usun_dowolny(int n);
void usun_pierwszy();
bool czy_pusta();
void clean_list();
// bedzie jeszcze usuwanie elementów po idndeksie i jakimś sposobem żeby listy mogły się wymieniać elementami
// więcej metod chyba nie potrzeba, bo kolejność u nas nie gra roli. chyba, że destruktor bo nie wiem czy c++ jest na tyle mądry żeby sam dorze usuwał te listy, chwilowo czyści po nas windows bo program i

lista(): head(nullptr), ogon(nullptr) {}      // każdy obiekt 'lista' trzyma w sobie wskaźnik na swój ogon i głowę, później nich operuje latając po węzłach

private:
/*!
  * \brief head
  * wskaźnik na głowę
  */
 node * head;
 /*!
  * \brief ogon
  * wskaźnik na ogon
  */
 node * ogon;

 //friend symulacja;

};


#endif // LISTA_H
