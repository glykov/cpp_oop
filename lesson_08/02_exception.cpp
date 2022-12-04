/**
 * Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, инициализирующий x значением параметра. 
 * Написать класс Bar, хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем) 
 * и имеющий метод set с единственным вещественным параметром a. 
 * Если y + a > 100, возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a. 
 * В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n. 
 * Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. 
 * В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
*/
#include <iostream>
#include <cmath>

class Ex
{
public:
    Ex(double val) : x(val) {}
    double get_code() { return x; }
private:
    double x;
};

class Bar
{
public:
    Bar() : y(0) {}
    void set(double a);
private:
    double y;
};

void Bar::set(double a)
{
    if (y + a > 100) {
        throw Ex(y * a);
    } else {
        y = a;
    }
}

int main()
{
    double val;
    Bar bar;
    
    try {
        while (true) {
            std::cout << "Enter a number (0 to exit): ";
            std::cin >> val;
            if (fabs(0 - val) < 1e-15) {
                break;
            }
            bar.set(val);
        }
    } catch (Ex ex) {
        std::cout << ex.get_code() << std::endl;
    }
    return 0;
}