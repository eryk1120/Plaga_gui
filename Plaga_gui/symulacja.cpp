#include "symulacja.h"


#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

void symulacja::fala()
{

    this->zaraza();
    this->hit();
    this->loty();
}

void symulacja::zaraza()
{
    for( int i=0; i<this->size(); i++)
    {
        if (world[i].chorzy!=0 && world[i].ludnosc!=world[i].chorzy)
        {
            world[i].chorzy = world[i].chorzy * 5;   // tu wstawić algo zarazy z alphy potem

            if (world[i].chorzy > world[i].ludnosc)
                world[i].chorzy = world[i].ludnosc;  //limit
            world[i].old_ratio=world[i].ratio;
            world[i].ratio=100 * world[i].chorzy / world[i].ludnosc;

        }
    }
    ;
}


void symulacja::hit()
{
    for (int i=0; i<this->size(); i++)
    {
        if(world[i].chorzy)
        {
            //lista  temp = world[i].graniczy_z;
            for (int j=0; j < world[i].graniczy_z.jak_dluga();j++)
            {
                int target = world[i].graniczy_z.dej(j);
                if (target<0)
                    return;
                if (world[target].chorzy)
                {
                    world[i].graniczy_z.usun_dowolny(target);
                    continue;
                }
                int obrona = world[target].health_care+world[target].GNI;
                int atak = world[i].ratio;
                srand(time(0));
                atak = atak + rand()%(10);
                if (atak >= obrona)
                {
                    this->infect(target,10);
                    world[i].graniczy_z.usun_dowolny(target);
                    return;
                }


            }
        }
    }
    return;
}
void symulacja::loty()
{
    //lista  temp = lotne;
    int stop = lotne.jak_dluga();
    for (int j=0; j<stop;j++)
    {
        int target = lotne.dej(j);
        if (target<0)
            return;
        if (world[target].chorzy)
        {
            lotne.usun_dowolny(target);
            continue;
        }
        int obrona = world[target].health_care + world[target].GNI;
        int atak = 50;
        //srand(time(0));
        atak = atak + rand()%(100-atak);
        if (atak >= obrona)
        {
            this->infect(target,10);
            lotne.usun_dowolny(target);
            return;

        }

    }
    return;

}
void symulacja::infect(int i,int liczba)
{
    world[i].chorzy+=liczba;

}


void symulacja::dodaj_element(string NazwaPliku)
{
    ifstream plik (NazwaPliku.c_str());

    if(!plik.good())
        return;



    while (!plik.eof())
    {
        Kraje kraj;
        kraj.nazwa="";
        plik.ignore(1);
        while (!plik.eof() && !(plik.peek()>='0' && plik.peek()<='9'))   // bierze sobie po literce nazwę państwa
        {                                                                // i zerka czy następna jest cyfrą

            char temp;
            plik.get(temp);
            kraj.nazwa=kraj.nazwa + temp;
            // robi słowow po literce
        }
//jak następna jest cyfrą to czyta normalnie dane do odpowiednich miejsc
        plik  >> kraj.ludnosc>> kraj.powierzchnia >> kraj.dos_morze >> kraj.health_care >> kraj.GNI;
        kraj.gestosc = kraj.ludnosc/kraj.powierzchnia;
        world.push_back(kraj);
    }
    return ;
}

void symulacja::dodaj_chorby(string nazwa_pliku)
{
    ifstream plik (nazwa_pliku.c_str());

    if(!plik.good())
    {
        return;
    }

    while (!plik.eof())
    {
        Choroby choroba;
        choroba.nazwa_choroby="";
        plik.ignore(1);
        while (!plik.eof() && !(plik.peek()>='0' && plik.peek()<='9'))   // bierze sobie po literce nazwę państwa
        {                                                                // i zerka czy następna jest cyfrą

            char temp;
            plik.get(temp);
            choroba.nazwa_choroby=choroba.nazwa_choroby + temp;
            // robi słowow po literce
        }
//jak następna jest cyfrą to czyta normalnie dane do odpowiednich miejsc
        plik  >>choroba.BRN>>choroba.czas;
        virus.push_back(choroba);
    }
    return ;

}

int symulacja::dej_ratio(int i)
{
    return world[i].ratio;
}

int symulacja::dej_BRN(int i)
{
    return virus[i].BRN;
}

int symulacja::dej_czas(int i)
{
    return virus[i].czas;
}

void symulacja::czytaj_macierz (string NazwaPliku)   // bierze po linijce z pliku i dodaje do elementu vectora nowy element jak napotka '1' (np w linijce 24, linijka[100]==1 więc kraj 24 graniczy z krajem 100
{
    ifstream plik (NazwaPliku.c_str());
    if (! plik.good())
        return;
    int n=0; // licznik na którym państwie jest
    while ( ! plik.eof() )
    {

        string x;
        getline ( plik , x ); // wczytuje do x linijkę macierzy i na niej operuje
        for (unsigned int i=0 ; i < x.size() ; i++ )  // tu jest coś nie tak, albo znowu jakieś badbity z excela
                                                      // bo albo czyta że nie ma nic albo że jest wszystko
        {                                             // a lista sama w sobie działa
            if (x[i] == '1')
                world[n].graniczy_z.dodaj_element_po(i); // i można traktować jako indeks państwa mktóre graniczy z państwem nr n
        }
        n++;
    }
}

symulacja::symulacja()
{
    dodaj_element("tekst/Afryka.txt");
    dodaj_element("tekst/Ameryki.txt");
    dodaj_element("tekst/Oceania.txt");
    dodaj_element("tekst/Eurazja.txt");
    czytaj_macierz("tekst/sasiedztwo.txt");
    dodaj_chorby("tekst/Choroby.txt");

    for(unsigned int i=0; i<world.size(); i++)
    {
        lotne.dodaj_element_po(i);
        L_ludzi+=world[i].ludnosc;
    }
}

symulacja::~symulacja()
{

}

int symulacja::size()
{
    return world.size();
}

int symulacja::size2()
{
    return virus.size();
}

bool symulacja::czy_zmiana(int i)
{
    if (world[i].ratio != world[i].old_ratio)
        return true;
    return false;
}
string symulacja::dej_nazwe(int i)
{
    return world[i].nazwa;
}

int symulacja::szukaj_indeks(QString Nazwa)
{
    for (unsigned int i=0; i<world.size();i++)
        if(Nazwa == QString::fromStdString( (world[i].nazwa) ))
            return i;
    return 0;
}

int symulacja::szukaj_indeks(string Nazwa)
{
    for (unsigned int i=0; i<world.size();i++)
        if ( Nazwa == world[i].nazwa)
            return i;
    return -1;
}
void symulacja::set_data(int m, int r)
{
    start.set(m,r);
    aktualny.set(m,r);
}
void symulacja::set_koniec(int m, int r)
{
    koniec.set(m,r);
}

string symulacja::dej_chorbe(int i)
{
    return virus[i].nazwa_choroby;
}

int symulacja::dej_ludnosc(int i)
{
    return  world[i].ludnosc;
}

int symulacja::dej_chorzy(int i)
{
    return world[i].chorzy;
}

int symulacja::dej_powierzchnia(int i)
{
    return world[i].powierzchnia;
}


bool symulacja::czy_koniec()
{
    for(int i=0;i<world.size();i++)
        if (world[i].chorzy<world[i].ludnosc)

            return false;
    return true;
}
