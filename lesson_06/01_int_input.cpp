/**
 * Создать программу, которая считывает целое число типа int. 
 * И поставить «защиту от дурака»: если пользователь вводит что-то кроме одного целочисленного значения, 
 * нужно вывести сообщение об ошибке и предложить ввести число еще раз.
*/
#include <iostream>

int int_input()
{
    int result;

    std::cout << "Please, enter a number: ";
    while (true) {
        std::cin >> result;

        if (!std::cin) {
            std::cin.clear();
            while (std::cin.get() != '\n') {
                continue;
            }
            std::cout << "Please, enter a number: ";
        } else {
            break;
        }
    }

    return result;
}

int main()
{
    int num;

    num = int_input();

    std::cout << "You entered number " << num << "\n";

    return 0;
}