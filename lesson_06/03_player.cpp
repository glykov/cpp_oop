/**
 * Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
 *
 * • virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. 
 *  Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
 * • void Win() const- выводит на экран имя игрока и сообщение, что он выиграл.
 * • void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
 * • void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
*/

#include "generic_player.h"
#include <cctype>

class Player : public GenericPlayer
{
public:
    virtual bool is_hitting() const
    {
        std::string answer;
        std::cout << "Do you need one more card? [Y/N]: ";
        getline(std::cin, answer);

        if (tolower(answer[0]) == 'y') {
            return true;
        }
        return false;
    }
    void win() const { std::cout << name << " wins!\n"; }
    void lose() const { std::cout << name << " lose!\n"; }
    void push() const { std::cout << name << " draw!\n"; }
};
