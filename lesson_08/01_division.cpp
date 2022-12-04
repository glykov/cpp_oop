/**
 * Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров 
 * и запускать исключение DivisionByZero, если второй параметр равен 0. 
 * В функции main выводить результат вызова функции div в консоль, а также ловить исключения.
*/
#include <iostream>
#include <exception>
#include <cmath>

class DivisionByZero : public std::exception
{
public:
    virtual const char* what() { return "division by zero exception"; }
};

// в стандартной библиотеке есть функция div_t div(int, int), которая
// вызывается вместо шаблонной функции при ее вызове с целочисленными параметрами
// и, хотя, она определена в cstdlib, который я явным образом не включаю, она все равно замещает
// мою шаблонную функцию и сыпятся ошибки компиляции о невозможности привести div_t к int
// поэтому я изменил имя моей шаблонной функции на divide  
template<typename T>
T divide(T dividend, T divisor)
{
    double epsilon = 1e-15;
    if (fabs(0 - divisor) < epsilon) {
        throw DivisionByZero();
    }
    return dividend / divisor;
}

int main()
{
    try {
        std::cout << divide(10.0, 3.0) << std::endl;
        std::cout << divide(10.0, 0.0) << std::endl;
    } catch (DivisionByZero ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
