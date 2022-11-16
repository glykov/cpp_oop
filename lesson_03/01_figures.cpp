/**
 * Создать абстрактный класс Figure (фигура). 
 * Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). 
 * Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). 
 * Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь). 
 * Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
*/
#include <iostream>

class Figure
{
public:
    virtual ~Figure()
    {}

    virtual double area() = 0;
};

class Parallelogram : public Figure
{
protected:
    double a;
    double b;
public:
    Parallelogram(double side, double height)
    : a(side), b(height)
    {}

    Parallelogram(const Parallelogram& other)
    : a(other.a), b(other.b)
    {}

    Parallelogram& operator=(const Parallelogram& other)
    {
        if (this == &other)
            return *this;
        
        this->a = other.a;
        this->b = other.b;

        return *this;
    }

    ~Parallelogram()
    {}

    double area() { return a * b; }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(double side_a, double side_b)
    : Parallelogram(side_a, side_b)
    {}

    Rectangle(const Rectangle &other) = default;
    Rectangle& operator=(const Rectangle& other) = default;
    ~Rectangle() = default;
    // функция area не переопределена, потому что
    // формула находжения площади сторона_1 * сторона_2
    // совпадает с формулой для параллелограмма, только переменные интерпретируются иначе
};

class Square : public Parallelogram
{
public:
    Square(double side)
    : Parallelogram(side, side)
    {}

    Square(const Square& other) = default;
    Square& operator=(const Square& other) = default;
    ~Square() = default;
    // функция area не переопределена, потому что
    // формула находжения площади сторона_1 * сторона_2
    // совпадает с формулой для параллелограмма, только переменные для сторон одинаковые
    // и формула редуцируется до 2 * сторона
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(double diagonal_1, double diagonal_2)
    : Parallelogram(diagonal_1, diagonal_2)
    {}

    Rhombus(const Rhombus& other) = default;
    Rhombus& operator=(const Rhombus& other) = default;
    ~Rhombus() = default;
    
    double area() { return (a * b) / 2.0; }
};

class Circle : public Figure
{
private:
    double r;
public:
    Circle(double radius)
    : r(radius)
    {}

    Circle(const Circle& other) = default;
    Circle& operator=(const Circle& other) = default;
    ~Circle() = default;

    double area() { return 3.14159 * r * r; }
};

int main()
{
    Figure* zoo[] = {
        new Parallelogram(2.0, 3.0),
        new Rectangle(3.0, 4.0),
        new Square(4.0),
        new Rhombus(4.0, 5.0),
        new Circle(1.0)
    };

    for (auto fig : zoo) {
        std::cout << fig->area() << std::endl;
    }
    
    return 0;
}