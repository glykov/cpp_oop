/**
 * Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.
*/
#include <iostream>

std::ostream& my_endl(std::ostream& os)
{
    return os << '\n' << '\n' << std::flush;
}

int main()
{
    std::cout << "try my endl" << my_endl;
    std::cout << "next line\n";
    return 0;
}