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
    /*!
     * \brief The Kraje struct
     * struktura zawierająca dane na temat państwa
     */
    struct Kraje{
        /*!
         * \brief nazwa nazwa kraju
         */
        string nazwa;
        /*!
         * \brief ludnosc
         * l ludności
         *
         */
        unsigned int ludnosc;
        /*!
         * \brief chorzy
         * l zarażonych
         *
         */
        unsigned int chorzy=0;
        /*!
         * \brief powierzchnia
         * pierzchnia w km^2
         */
        unsigned int powierzchnia;
        /*!
         * \brief gestosc
         * gęstość zaludnienia
         */
        unsigned int  gestosc;
        /*!
         * \brief klimat
         *  dana czy klimat ma wpływ na rozpirzestrzenianie się
         */
        bool klimat;
        /*!
         * \brief dos_morze
         * true == dostęp do morza
         */
        bool dos_morze;
        /*!
         * \brief health_care
         * stopień health care państwa
         */
        int health_care;
        /*!
         * \brief GNI
         * stopień GNI
         */
        int GNI;
        /*!
         * \brief graniczy_z
         * lista indeksów państw z jakimi graniczy państwo
         */
        lista graniczy_z;  // jest lista bo mniejsza będzie o wiele
    };

    struct Choroby
    {
       string nazwa_choroby; //! Nazwy dostępnych w symulacji chorób
       int BRN; //! Basic Reproductive Number odpowiadający ilości przypadków zarażenia generowanych przez jeden obiekt w czasie inkubacyjnym choroby w zdrowym społeczeństwie
       int czas; //!czas inkubacyjny choroby
       bool czy_pasozyt; //! zmienna 0/1 mówiąca czy dana choroba jest wywołana pasożytem lub innym źródłem
    };



    /*!
      * \brief world
      * vector przetzrymujący dane krajów
      */
     vector<Kraje>  world;
     vector<Choroby> virus;
     //czas start, aktualny, koniec;
     //long long int infected=0, L_ludzi=0;
     /*!
      * \brief lotne
      * lista potencjalnych państw do zarażenia drogą lotną
      */
     lista lotne;

public:
     /*!
      * \brief start
      * czas startu
      * \brief aktualny
      * czas aktulany
      * \brief koniec
      * czas końca
      */

     czas start, aktualny, koniec;

public:



     // konstrukcja
     /*!
      * \brief symulacja
      * konstruktor
      */
     symulacja();
     ~symulacja();
     /*!
      * \brief reset
      * meotda resetująca chorobę
      */
     void reset();

     //pomocnicze konstruktora
     /*!
      * \brief dodaj_element
      * tworzy wektor z państwami
      * \param nazwa_pliku
      * ścieżka pliku z którego ma pobrać dane
      */
     void dodaj_element(string nazwa_pliku);// tworzy wektor z krajami
     void dodaj_chorby(string nazwa_pliku); //!tworzy wektor z danymi chorób
     /*!
      * \brief czytaj_macierz
      * dodaje do wektora listy sąsiadów
      * \param NazwaPliku
      * ścieżka pliku z macierzą sąsiedztwa
      */
     void czytaj_macierz (string NazwaPliku);// dodaje do gotowego wektora listy sąsiadów


     //zaraza
     /*!
      * \brief fala
      * symulacja jednego miesiąca rozprzestrzeniania się choroby (w państwie macierzystym i ekspansja)
      *
      */
     void fala();
     /*!
      * \brief zaraza
      * symulacja jednego miesiąca rozprzestrzeniania się choroby w państwie
      */
     void zaraza();
     /*!
      * \brief hit
      * zarażanie sąsiadów państwa
      */
     void hit();
     /*!
      * \brief loty
      * zarażanie drogą lotną
      */
     void loty();
     /*!
      * \brief czy_koniec
      * sprawdza czy wszystkie państwa są już zarażone
      * \return wartość odpowiedzi na pytanie czy koniec
      */
     bool czy_koniec();


     //utility

     int size(); //! zwraca wielkość  wektora Kraje
     int size2(); //! zwraca wielkość wektora Choroby

     void infect(int i,int liczba);
     /*!
      * \brief szukaj_indeks
      * szuka indeksu państwa o nazwie
      * \param Nazwa nazwa państwa szukanego
      * \return  indeks znalezionego państwa
      */
     int szukaj_indeks(string Nazwa);
     int szukaj_indeks(QString Nazwa);
     /*!
      * \brief set_data
      * ustawiwa aktualną datę
      * \param m miesiąc
      * \param r rok
      */
     void set_data(int m, int r);
     /*!
      * \brief set_koniec
      * ustawia datę końca
      * \param m miesiąc
      * \param r rok
      */
     void set_koniec(int m, int r);

     string dej_chorbe(int); //! zwraca indeks wybranej choroby
     string dej_nazwe(int);
     /*!
      * \brief dej_ludnosc
      * \param i indeks państwa
      * \return ludność
      */
     int dej_ludnosc(int i);
     /*!
      * \brief dej_chorzy
      * \param i ideks państwa
      * \return l. chorych
      */
     int dej_chorzy(int i);
     /*!
      * \brief dej_powierzchnia
      * \param i indeks państwa
      * \return powierzchnia państwa
      */
     int dej_powierzchnia(int i);
     int dej_ratio(int i); //! zwraca procentowy stosunek liczby chorych do całkowitej liczby ludności
     int dej_BRN(int i); //! zwraca współczynnik BRN wybranej choroby
     /*!
      * \brief dej_czas
      * \param i indeks państwa
      * \return zwraca aktualnyc czas
      */
     int dej_czas(int i);

     double ustaw_b(int i); //! funkcja ustala wartość współczynnika klimatycznego w zależności od wybranego państwa, aktualnego miesiąca oraz typu choroby

};
#endif // VECTOR_H
