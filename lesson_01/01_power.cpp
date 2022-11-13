/**
 * Создать класс Power, который содержит два вещественных числа. 
 * Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. 
 * Еще создать два метода: один с именем set, который позволит присваивать значения объявленным в классе переменным, 
 * второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. 
 * Задать значения этих двух чисел по умолчанию.
*/
#include <iostream>

class Power
{
private:
    double m_base;
    double m_exp;
public:
    Power()
    : m_base(2), m_exp(10)
    { }

    Power(double base, double exp)
    : m_base(base), m_exp(exp)
    { }

    Power(Power &other)
    : m_base(other.m_base), m_exp(other.m_exp)
    { }

    void set(double base, double exp)
    {
        m_base = base;
        m_exp = exp;
    }

    double calculate()
    {
        double result = 1;

        for (int i = 0; i < m_exp; i++) {
            result *= m_base;
        }

        return result;
    }
};

int main()
{
    Power p1;
    std::cout << p1.calculate() << std::endl;

    p1.set(5, 2);
    std::cout << p1.calculate() << std::endl;

    Power p2(3, 4);
    std::cout << p2.calculate() << std::endl;

    Power p3 = p2;
    std::cout << p3.calculate() << std::endl;

    return 0;
}