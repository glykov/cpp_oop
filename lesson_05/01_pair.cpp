/**
 * Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
*/
#include <iostream>

template<typename T>
class Pair
{
public:
    Pair()
    : first(0), second(0)
    {}

    Pair(T one, T two)
    : first(one), second(two)
    {}

    void print()
    {
        std::cout << first << " " << second << std::endl;
    }

    T get_first() const { return first; }
    T get_second() const { return second; }

    void set_first(T value) { first = value; }
    void set_second(T value) { second = value; }
private:
    T first;
    T second;
};

int main()
{
    Pair<int> p1(6, 9);
    std::cout << "First pair: ";
    p1.print();

    Pair<double> p2(3.4, 7.8);
    std::cout << "Second pair: ";
    p2.print();

    return 0;
}