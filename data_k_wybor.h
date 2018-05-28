#ifndef DATA_K_WYBOR_H
#define DATA_K_WYBOR_H

#include <QDialog>

#include "czas.h"
namespace Ui {
class data_k_wybor;
}
/*!
 * \brief The data_k_wybor class
 * klasa zawierająca okno do wyboru daty zakończenia symulacji
 *
 */
class data_k_wybor : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief data_k_wybor
     * konstrutkor
     * \param parent
     * tym parametrem ojciec tego obiektu(np okno w którym jest wywołany)
     *
     */
    explicit data_k_wybor(QWidget *parent = 0);      
    ~data_k_wybor();
    /*!
     * \brief startowe
     * obiekt przechowywujący informacje na temat daty początku sumulacji
     */
    czas startowe;
    /*!
     * \brief koncowe
     * obiekt przechowywujący informacje na temat końca sumulacji
     */
    czas koncowe;
    /*!
     * \brief set_up
     * funkcja ustawiająca limity dla użytkownika w wyborze daty końcowej
     */
    void set_up();

private slots:
    void on_ook_clicked();

private:
    Ui::data_k_wybor *ui;

};

#endif // DATA_K_WYBOR_H
