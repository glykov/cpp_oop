/**
 * Создать класс Card, описывающий карту в игре БлэкДжек. 
 * У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой). 
 * Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. 
 * Также в этом классе должно быть два метода:
 *   метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
 *   метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/
#include <iostream>

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum Face { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card
{
public:
    Card(Suit s, Face f, bool pos)
    : suit(s), face(f), face_up(pos)
    {}

    ~Card()
    {}

    void flip() { face_up = !face_up; }
    int get_value() const { return (int)face; }

private:
    Suit suit;
    Face face;
    bool face_up;
};

int main()
{
    Card c(HEARTS, QUEEN, false);
    std::cout << c.get_value() << std::endl;
    return 0;
}