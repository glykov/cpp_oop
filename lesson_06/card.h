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
    Face get_face() const { return face; }
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
    Suit suit;
    Face face;
    bool face_up;
};
