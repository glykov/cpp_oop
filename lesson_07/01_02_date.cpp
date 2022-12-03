/**
 * Создайте класс Date с полями день, месяц, год и методами доступа к этим полям. 
 * Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя today и date. 
 * Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы доступа к полям класса Date, 
 * а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода. 
 * Затем переместите ресурс, которым владеет указатель today в указатель date. 
 * Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.
*/
#include <iostream>
#include <memory>

class Date
{
public:
    Date(int a_day, int a_month, int a_year)
    : day(a_day), month(a_month), year(a_year)
    {}

    int get_day() const { return day; }
    int get_month() const { return month; }
    int get_year() const { return year;}

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
private:
    int day;
    int month;
    int year;
};

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.day << "/" << date.month << "/" << date.year;
    return os; 
}

/**
 * По условию предыдущей задачи создайте два умных указателя date1 и date2.

• Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой (сравнение происходит по датам). 
Функция должна вернуть более позднюю дату.
• Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.

Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.
*/

// Решил в этом задании поработать с shared_ptr для разнообразия. 
// Каких-то особых причнин использовать shared_prt вместо unique_ptr, в данном случае я не вижу или они все-таки есть?

std::shared_ptr<Date> get_later_date(std::shared_ptr<Date> first, std::shared_ptr<Date> second)
{
    if (first->get_year() > second->get_year()) {
        return first;
    } else if (first->get_year() < second->get_year()) {
        return second;
    } else if (first->get_month() > second->get_month()) {
        return first;
    } else if (first->get_month() < second->get_month()) {
        return second;
    } else if (first->get_day() > second->get_day()) {
        return first;
    }
    return second;
}

// если использовать unique_ptr в данном случае, то пришлось бы делать обмен через вызов std::move?
// не сразу понял, почему значения не меняются, вроде передаю указатели, а потом сообразил, что передаю объекты по значению,
// а не сами указатели, поэтому пережача по ссылке сработала :-)
// решил не использовать std::shared_ptr.swap(), а сделать вручную
void swap_dates(std::shared_ptr<Date>& first, std::shared_ptr<Date>& second)
{
    std::shared_ptr<Date> temp = first;
    first = second;
    second = temp;
    // можно и так:
    // first.swap(second);
}

int main()
{
    std::unique_ptr<Date> today(new Date(30, 12, 2022));
    std::cout << "Today's day: " << today->get_day() << std::endl;
    std::cout << "Today's month: " << today->get_month() << std::endl;
    std::cout << "Today's year: " << today->get_year() << std::endl;
    std::cout << "Today's date: " << *today << std::endl;

    std::unique_ptr<Date> date = std::move(today);
    std::cout << "date: " << date.get() << ", today: " << today.get() << std::endl;

    std::shared_ptr<Date> date1(new Date(1, 12, 2022));
    std::shared_ptr<Date> date2(new Date(30, 11, 2022));
    std::cout << "Date 1: " << *date1 << std::endl;
    std::cout << "Date 2: " << *date2 << std::endl;

    std::cout << "The later date is " << *(get_later_date(date1, date2)) << std::endl;

    swap_dates(date1, date2);
    std::cout << "Date 1: " << *date1 << std::endl;
    std::cout << "Date 2: " << *date2 << std::endl;

    return 0;
}