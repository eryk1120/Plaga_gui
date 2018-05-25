#include <iostream>
#include "czas.h"
using namespace std;
czas::czas()
{
    rok=2018;
    miesiac= 1;

}
czas::czas(int miesiac_, int rok_)
{
    rok=rok_;
    miesiac=miesiac_;
    if (miesiac_>12)
        miesiac=1;
}

void czas::set(int m, int r)
{
    rok=r;
    miesiac=m;
    if (m>12)
        miesiac=1;
}

czas::~czas()
{

}

int ::czas::odstep_miedzy( czas K)
{
    int counter=0;
    if (this->miesiac < K.miesiac)
    {
        counter = this->miesiac - K.miesiac;
    }
    else if(this->miesiac > K.miesiac)
    {
        counter = -(this->miesiac - K.miesiac);
    }
    else
    {

    }
    counter += (K.rok - this->rok * 12);
    return counter;

}
