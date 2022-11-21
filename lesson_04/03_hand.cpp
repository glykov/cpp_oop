/**
 * Реализовать класс Hand, который представляет собой коллекцию карт. 
 * В классе будет одно поле: вектор указателей карт 
 * (удобно использовать вектор, т.к. это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card). 
 * Также в классе Hand должно быть 3 метода:
 *      метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
 *      метод Clear, который очищает руку от карт
 *      метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).
*/
#include <iostream>
#include <vector>
#include "card.h"

class Hand
{
public:
    Hand() {};
    ~Hand() {};

    void add(Card* card) { hand.push_back(card); }
    void clear() { hand.clear(); }
    int get_value();

private:
    std::vector<Card*> hand;
};

int Hand::get_value()
{
    int result = 0;
    for (auto i : hand) {
        if (i->get_face() == ACE && result <= 21) {
            result += 11;
        } else {
            result += i->get_value();
        }
    }
    return result;
}

int main()
{
    return 0;
}