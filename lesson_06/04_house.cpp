/**
 * Реализовать класс House, который представляет дилера. Этот класс наследует от класса GenericPlayer. У него есть 2 метода:
 * 
 * • virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
 * • void FlipFirstCard() - метод переворачивает первую карту дилера.
*/
#include "generic_player.h"

class House : public GenericPlayer
{
public:
    virtual bool is_hitting() const
    {
        if (get_value() <= 16) {
            return true;
        }
        return false;
    }
    void flip_first_card() {
        hand[0]->flip();
    }
};
