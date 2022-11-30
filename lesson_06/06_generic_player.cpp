/**
 * Написать перегрузку оператора вывода для класса Card. 
 * Если карта перевернута рубашкой вверх (мы ее не видим), вывести ХХ, если мы ее видим, вывести масть и номинал карты. 
 * Также для класса GenericPlayer написать перегрузку оператора вывода, 
 * который должен отображать имя игрока и его карты, а также общую сумму очков его карт.
*/
#include "generic_player.h"

std::ostream& operator<<(std::ostream& os, const GenericPlayer& gp)
{
    os << gp.name << " has following cards:" << std::endl;
    for (auto card : gp.hand) {
        os << card;
    }
    os << "The total value is " << gp.get_value() << std::endl;
    return os;
}