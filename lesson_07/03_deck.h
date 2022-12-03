/**
 * 3. Создать класс Deck, который наследует от класса Hand и представляет собой колоду карт. Класс Deck имеет 4 метода:

• vold Populate() - Создает стандартную колоду из 52 карт, вызывается из конструктора.
• void Shuffle() - Метод, который тасует карты, можно использовать функцию из алгоритмов STL random_shuffle
• vold Deal (Hand& aHand) - метод, который раздает в руку одну карту
• void AddltionalCards (GenericPlayer& aGenerlcPlayer) - раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать

Обратите внимание на применение полиморфизма. В каких методах применяется этот принцип ООП?
*/
#ifndef __DECK_H__
#define __DECK_H__

#include "hand.h"

class Deck : public Hand
{
public:
    Deck();
    virtual ~Deck();
    
    void populate();
    void shuffle();
    void deal(Hand& hand);
    void additional_cards();
};

#endif