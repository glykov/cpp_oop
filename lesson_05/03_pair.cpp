/**
 * Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа. 
 * Этот шаблон класса должен наследовать частично специализированный класс Pair, 
 * в котором первый параметр — string, а второй — любого типа данных.
*/
#include <iostream>
#include <string>

template<typename T, typename U>
class Pair
{
public:
    Pair(T one, U two)
    : first(one), second(two)
    {}

    void print() { std::cout << first << " " << second; }
    
    T first;
    U second;
};


template<typename U>
class Pair<const std::string&, U>
{
public:
    Pair(const std::string& one, U two)
    : first(one), second(two)
    {}

    void print() { std::cout << first << " " << second; }

    std::string first;
    U second;
};

template<typename U>
class StringValuePair : public Pair<const std::string&, U>
{
public:
    StringValuePair(const std::string& one, U two)
    : Pair<const std::string&, U>(one, two)
    {}
};

int main()
{
    StringValuePair<int> svp("Amazing", 7);
    svp.print();
    std::cout << std::endl;
    
    return 0;
}