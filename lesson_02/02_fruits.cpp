/*
* Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
* У Fruit есть две переменные-члена: name (имя) и color (цвет).
* Добавить новый класс GrannySmith, который наследует класс Apple.
*/

#include <iostream>
#include <string>

enum Color {RED, GREEN, YELLOW, BLUE};

class Fruit
{
public:
    Fruit()
    : name(""), color(RED)
    {}

    Fruit(std::string the_name, Color the_color)
    : name(the_name), color(the_color)
    {}

    Fruit(const Fruit &fruit)
    : Fruit(fruit.name, fruit.color)
    {}

    ~Fruit()
    {}

    // mutators
    void set_name(std::string the_name) { name = the_name; }
    void set_color(Color the_color) { color = the_color; }

    // accessors
    std::string get_name() const { return name; }
    std::string get_color() const;

protected:
    std::string name;
    Color color;
};

std::string Fruit::get_color() const
{
    switch (color) {
        case RED: return "red";
        case GREEN: return "green";
        case YELLOW: return "yellow";
        case BLUE: return "blue";
        default: return "undefined";
    }
}

class Apple : public Fruit
{
public:
    Apple(std::string the_name="apple", Color the_color=RED)
    : Fruit(the_name, the_color)
    {}

    Apple(Color the_color)
    : Fruit("apple", the_color)
    {}

    Apple(Apple &apple)
    : Fruit(apple.name, apple.color)
    {}

    ~Apple()
    {}
};

class Banana : public Fruit
{
public:
    Banana(std::string the_name="banana", Color the_color=YELLOW)
    : Fruit(the_name, the_color)
    {}

    Banana(Banana &banana)
    : Fruit(banana.name, banana.color)
    {}

    ~Banana()
    {}
};

class GrannySmith : public Apple
{
public:
    GrannySmith(std::string the_name="GrannySmith apple", Color the_color=GREEN)
    : Apple("GrannySmith apple", GREEN)
    {}

    GrannySmith(Color the_color)
    : Apple("GrannySmith apple", the_color)
    {}

    GrannySmith(GrannySmith &gs)
    : Apple(gs.name, gs.color)
    {}

    ~GrannySmith()
    {}
};

int main()
{
    Apple a(RED);
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.get_name() << " is " << a.get_color() << ".\n";
    std::cout << "My " << b.get_name() << " is " << b.get_color() << ".\n";
    std::cout << "My " << c.get_name() << " is " << c.get_color() << ".\n";

    return 0;
}