/**
 * Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
*/
#include <iostream>

template<typename T, typename U>
class Pair
{
public:
    Pair(T one, U two)
    : first(one), second(two)
    {}

    T get_first() const;
    U get_second() const;
    void print() const;

    void set_first(T value);
    void set_second(U value);

    template<typename A, typename B>
    friend std::ostream& operator<<(std::ostream& os, const Pair<A, B>& p);
private:
    T first;
    U second;
};

template<typename T, typename U>
T Pair<T, U>::get_first() const
{
    return first;
}

template<typename T, typename U>
U Pair<T, U>::get_second() const
{
    return second;
}

template<typename T, typename U>
void Pair<T, U>::set_first(T value)
{
    first = value;
}

template<typename T, typename U>
void Pair<T, U>::set_second(U value)
{
    second = value;
}

template<typename T, typename U>
void Pair<T, U>::print() const
{
    std::cout << first << " " << second;
}

template<typename A, typename B>
std::ostream& operator<<(std::ostream& os, const Pair<A, B>& p)
{
    os << p.first << " " << p.second;
    return os;
}

int main()
{
    Pair<int, double> p1(6, 7.8);
    std::cout << p1;
    std::cout << std::endl;

    Pair<double, int> p2(3.4, 5);
    std::cout << p2;
    std::cout << std::endl;

    return 0;
}