#ifndef CZAS_H
#define CZAS_H


class czas
{
private:
    //enum month {nic, styczen, luty, marzec, kwiecien, maj, czerwiec,
      //            lipiec, sierpien, wrzesien, pazdziernik, listopad, grudzien};


    int  rok;
    int  miesiac;
public:
    czas();
    czas(int miesiac_,int rok_);
    ~czas();


    void set(int m,int r);

    czas & operator ++ ()
    {
        miesiac+=1;
        if(miesiac>12)
        {
            rok++;
            miesiac=1;
        }
        return *this;
    }

    czas & operator ++ (int)
    {
        miesiac+=1;
        if(miesiac>12)
        {
            rok++;
            miesiac=1;
        }
        return *this;
    }

};

#endif // CZAS_H
