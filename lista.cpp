
#include "lista.h"

using namespace std;


void lista::dodaj_element_po(int inde)
{
    node * aktualny= new node(inde);
    if (head == nullptr)
        head = aktualny;
    else if (ogon == nullptr)
    {
        ogon = aktualny;
        head -> nast = ogon;
    }
    else
    {
        ogon -> nast = aktualny;
        ogon = aktualny;
    }
}

void lista::wypisz_liste ()
{
    node*temp;
    temp=head;
    while (temp != NULL)
    {
        //cout << temp->indeks << '\t';
        temp = temp->nast;

    }
}


void lista::usun_pierwszy()
{
    node *tmp; /*
    tmp=head->nast;
    delete head;
    head=tmp;
    */
    tmp = head;
    head = head->nast;
    delete tmp;
}


void lista::usun_dowolny(int numer)
{

    if (head == nullptr)
        return;

    if (head->indeks == numer)
    {
        this->usun_pierwszy();
        return;
    }
    node * temp=head;
    while(temp->nast!=NULL)
    {int x = temp->indeks;
        if(temp->nast->indeks == numer)
        {

            node * temp2;
            temp2=temp->nast;
            temp->nast=temp->nast->nast;
            delete temp2;
            break;
        }
        temp=temp->nast;

    }
        return;

    }

    bool lista::czy_pusta()
    {
        if (head == nullptr)
            return true;
        return false;
    }

    void lista::clean_list()
    {
        while(!this->czy_pusta())
                {
                    this->usun_pierwszy();
                }
                return;
    }

    int lista::dej(int N)
    {
        //if (head==NULL)
        //    return -1;           // sygnał, że koniec listy
        if(head==NULL)
            return-1;
        node * temp = head;
        for (int i=0;i<N;i++)
        {
            if (temp->nast==NULL)
                return -1;
            temp=temp->nast;
        }
        int x = temp->indeks;
        return x;
    }

int lista::jak_dluga()
{
    int n = 0;
    node * temp = head;
    while (temp != NULL)
    {
        temp=temp->nast;
        n++;
    }
    return n;
}
