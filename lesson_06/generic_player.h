/**
 * От класса Hand наследует класс GenericPlayer, который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер. 
 * Создать класс GenericPlayer, в который добавить поле name - имя игрока. Также добавить 3 метода:
 * • IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
 * • IsBoosted() - возвращает bool значение, есть ли у игрока перебор
 * • Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
*/
#include "hand.h"
#include <string>
#include <iostream>

class GenericPlayer : public Hand
{
public:
    GenericPlayer(std::string the_name) : name(the_name) {}
    virtual ~GenericPlayer() {}

    virtual bool is_hitting() = 0;
    bool is_boosted() { return get_value() > 21; }
    void boost() { std::cout << name << " is boosted!" << std::endl; }
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& gp);
protected:
    std::string name;
};

// int main()
// {
//     return 0;
// }