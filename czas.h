#ifndef CZAS_H
#define CZAS_H

/*!
 * \brief The czas class
 * jest to klasa przetrzymująca informacje na temat miesiąca i roku
 */

class czas
{
private:
    //enum month {nic, styczen, luty, marzec, kwiecien, maj, czerwiec,
      //            lipiec, sierpien, wrzesien, pazdziernik, listopad, grudzien};

public:
    /*!
     * \brief rok
     * zmienna typu int przetrzymująca informacje na temat aktualnego roku
     */
    int  rok;
    /*!
     * \brief miesiac
     * zmienna typu int przetrzymująca informacje na temat danego miesiąca
     * przyjmuje wartość <1;12>
     */
    int  miesiac;
public:
    /*!
     * \brief czas
     * konstruktor dla wartości miesiąc == 0, rok == 0
     */
    czas();
    /*!
     * \brief czas
     * konstruktor obiektu czas przyjmujący datę przy tworzeniu
     * \param miesiac_
     * parametr typu int reprezentujący miesiąc (jego numer)
     * \param rok_
     * parametr reprezentujący rok
     *
     */
    czas(int miesiac_,int rok_);
    ~czas();

    /*!
     * \brief set
     * ostawia datę reprezentowaną przez obiekt
     * \param m MIESIĄC
     * odpowiada miesiącowi ( gdy nie zawiera się w 12 to przyjmuje wartość 0)
     * \param r ROK
     * odpowiada roku
     *
     */
    void set(int m,int r);

    /*!
     * \brief operator ++
     * funkcja przesuwa datę obiektu o jeden miesiąc(przy przekroczeniu 12 miesięcy dodaje rok)
     * \return data(miesiąc+1;rok)
     *
     */
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
    /*!
     * \brief operator ++
     * \return
     */
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

    int odstep_miedzy (czas K);

};

#endif // CZAS_H
