/**
 * Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. 
 * Перегрузить:
 *   математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
 *   унарный оператор (-)
 *   логические операторы сравнения двух дробей (==, !=, <, >, <=, >=). 
*/
#include <iostream>

class Fraction
{
public:
    Fraction()
    : numerator(0), denominator(1)
    {}

    Fraction(int n, int d)
    : numerator(n), denominator(d != 0 ? d : 1)
    {}

    Fraction(const Fraction& other)
    : numerator(other.numerator), denominator(other.denominator)
    {}

    ~Fraction()
    {}

    Fraction& operator=(const Fraction& other)
    {
        if (this == &other)
            return *this;

        this->numerator = other.numerator;
        this->denominator = other.denominator;
        return *this;
    }

    Fraction operator-()
    {
        return Fraction(-numerator, denominator);
    }

    // арифметические операторы
    friend Fraction operator+(const Fraction& left, const Fraction& rigth);
    friend Fraction operator+(const Fraction& left, int right);
    friend Fraction operator+(int left, const Fraction& right);
    // остальные перегружены для действия только с дробями, т.к. времени не хватает на все
    friend Fraction operator-(const Fraction& left, const Fraction& right);
    friend Fraction operator*(const Fraction& left, const Fraction& right);
    friend Fraction operator/(const Fraction& left, const Fraction& right);
    // логические операторы
    friend bool operator==(const Fraction& left, const Fraction& right);
    friend bool operator!=(const Fraction& left, const Fraction& right);
    friend bool operator<(const Fraction& left, const Fraction& right);
    friend bool operator>(const Fraction& left, const Fraction& right);
    friend bool operator<=(const Fraction& left, const Fraction& right);
    friend bool operator>=(const Fraction& left, const Fraction& right);
    // операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
private:
    int gcd(int x, int y);
    void reduce();
    int numerator;
    int denominator;
};

int Fraction::gcd(int x, int y)
{
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

void Fraction::reduce()
{
    int factor = gcd(numerator, denominator);
    numerator /= factor;
    denominator /= factor; 
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
    int num = left.numerator * right.denominator + right.numerator * left.denominator;
    int den = left.denominator * right.denominator;
    Fraction f(num, den);
    f.reduce();
    return f;
}

Fraction operator+(const Fraction& left, int right)
{
    int num = left.numerator + right * left.denominator;
    Fraction f(num, left.denominator);
    f.reduce();
    return f;
}

Fraction operator+(int left, const Fraction& right)
{
    return right + left;
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
    int num = left.numerator * right.denominator - right.numerator * left.denominator;
    int den = left.denominator * right.denominator;
    Fraction f(num, den);
    f.reduce();
    return f;
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
    int num = left.numerator * right.numerator;
    int den = left.denominator * right.denominator;
    Fraction f(num, den);
    f.reduce();
    return f;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
    int num = left.numerator * right.denominator;
    int den = left.denominator * right.numerator;
    Fraction f(num, den);
    f.reduce();
    return f;
}

bool operator==(const Fraction& left, const Fraction& right)
{
    return left.numerator * right.denominator == right.numerator * left.denominator;
}

bool operator!=(const Fraction& left, const Fraction& right)
{
    return !(left == right);
}

bool operator<(const Fraction& left, const Fraction& right)
{
    return left.numerator * right.denominator < right.numerator * left.denominator;
}

bool operator>(const Fraction& left, const Fraction& right)
{
    return left.numerator * right.denominator > right.numerator * left.denominator;
}

bool operator<=(const Fraction& left, const Fraction& right)
{
    return !(left > right);
}

bool operator>=(const Fraction& left, const Fraction& right)
{
    return !(left < right);
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction)
{
    char t;
    in >> fraction.numerator;
    in >> t;
    in >> fraction.denominator;
    return in;
}

int main()
{
    Fraction f1(1, 2), f2(2, 4), f3(1, 3);
    std::cout << "f1 = " << f1 << ", f2 = " << f2 << ", f3 = " << f3 << std::endl;
    Fraction f4;
    std::cout << "Enter a fraction: ";
    std::cin >> f4;
    std::cout << "f4 = " << f4 << std::endl;

    std::cout << "f1 + f3 = " << f1 + f3 << std::endl;
    std::cout << "f1 - f3 = " << f1 - f3 << std::endl;
    std::cout << "f1 * f3 = " << f1 * f3 << std::endl;
    std::cout << "f1 / f3 = " << f1 / f3 << std::endl;

    std::cout << std::boolalpha << "f1 == f2 is " << (f1 == f2) << std::endl;
    std::cout << std::boolalpha << "f1 != f3 is " << (f1 != f3) << std::endl;
    std::cout << std::boolalpha << "f1 > f3 is " << (f1 > f3) << std::endl;
    std::cout << std::boolalpha << "f1 < f3 is " << (f1 < f3) << std::endl;

    return 0;
}