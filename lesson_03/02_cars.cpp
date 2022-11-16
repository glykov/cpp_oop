/**
 * Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
 * Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). 
 * От этих классов наследует класс Minivan (минивэн). 
 * Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. 
 * Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. 
 * Обратить внимание на проблему «алмаз смерти».
*/
#include <iostream>
#include <string>

class Car
{
private:
    std::string company;
    std::string name;
public:
    Car(std::string the_company, std::string the_name)
    : company(the_company), name(the_name)
    {
        std::cout << "Car constructor\n";
    }

    ~Car()
    {
        std::cout << "Car destructor\n";
    }
};

class PassengerCar : virtual public Car
{
private:
    int num_doors;
public:
    PassengerCar(std::string company, std::string name, int number_of_doors)
    : Car(company, name), num_doors(number_of_doors)
    {
        std::cout << "PassengerCar constructor\n";
    }

    ~PassengerCar()
    {
        std::cout << "PassengerCar destructor\n";
    }
};

class Bus : virtual public Car
{
private:
    int num_seats;
public:
    Bus(std::string company, std::string name, int number_of_seats)
    : Car(company, name), num_seats(number_of_seats)
    {
        std::cout << "Bus constructor\n";
    }

    ~Bus()
    {
        std::cout << "Bus destructor\n";
    }
};

class Minivan : public PassengerCar, public Bus
{
public:
    Minivan(std::string company, std::string name, int number_of_doors, int number_of_seats)
    : PassengerCar(company, name, number_of_doors), Bus(company, name, number_of_seats), Car(company, name)
    {
        std::cout << "Minivan constructor\n";
    }

    ~Minivan()
    {
        std::cout << "Minivan destructor\n";
    }
};

int main()
{
    Minivan mv("company", "name", 5, 7);
    std::cout << "================================\n";

    return 0;
}

