/**
 * Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: 
 * m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). 
 * Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. 
 * Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. 
 * Написать функцию print(), которая будет выводить значения переменных-членов.
*/
#include <iostream>
#include <cstdint>

class RGBA
{
private:
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;
public:
    RGBA()
    {}

    RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {}

    RGBA(RGBA &other)
    : m_red(other.m_red), m_green(other.m_green), m_blue(other.m_blue), m_alpha(other.m_alpha)
    {}

    void print();
};

// cout воспринимает uint8_t как тип char и выводит всякую дичь, но static_cast<int> слишком долго писать, поэтому приведение сделал в стиле С
void RGBA::print()
{
    std::cout << "R: " << (int)m_red << ", G: " << (int)m_green << ", B: " << (int)m_blue << ", Alpha: " << (int)m_alpha << std::endl;
}

int main()
{
    RGBA rgba1;
    rgba1.print();

    RGBA rgba2(102, 255, 51, 255);
    rgba2.print();

    RGBA rgba3 = rgba2;
    rgba3.print();
}