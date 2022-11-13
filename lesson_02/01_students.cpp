/*
* Создать класс Person (человек) с полями: имя, возраст, пол и вес. 
* Определить методы переназначения имени, изменения возраста и веса. 
* Создать производный класс Student (студент), имеющий поле года обучения. 
* Определить методы переназначения и увеличения этого значения. Создать счетчик количества созданных студентов. 
* В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cassert>

enum Gender {MALE, FEMALE, UNDEFINED};

class Person
{
protected:
    std::string name;
    int age;
    Gender gender;
    double weight;

public:
    // constructors & destructor
    Person()
    : name(""), age(0), gender(UNDEFINED), weight(0.0)
    {}

    Person(std::string the_name, int the_age, Gender the_gender, double the_weight)
    : name(the_name), age(the_age), gender(the_gender), weight(the_weight)
    {}

    Person(const Person &p)
    : name(p.name), age(p.age), gender(p.gender), weight(p.weight)
    {}

    ~Person()
    {}

    // mutators
    void set_name(std::string the_name) { name = the_name; }
    void set_age(int the_age) { age = the_age; }
    void set_gender(Gender the_gender) { gender = the_gender; }
    void set_weight(double the_weight) { weight = the_weight; }

    // accessors
    std::string get_name() const { return name; }
    int get_age() const { return age; }
    Gender get_gender() const { return gender; }
    double get_weight() const { return weight; }
    std::string get_info() const;
};

std::string Person::get_info() const
{
    std::stringstream result;
    
    result << "Name: " << name << "\nAge: " << age;
    result << "\nGender: " << (gender == MALE ? "male" : (gender == FEMALE ? "female" : "undefined"));
    result << "\nWeight: " << weight << "\n";
    
    return result.str();
}

class Student : public Person
{
private:
    int year_of_study;
    static int student_counter;

public:
    Student()
    : Person(), year_of_study(0)
    { student_counter++; }

    Student(std::string the_name, int the_age, Gender the_gender, double the_weight, int year)
    : Person(the_name, the_age, the_gender, the_weight), year_of_study(year)
    { student_counter++; }

    Student(const Student &s)
    : Person(s.name, s.age, s.gender, s.weight), year_of_study(s.year_of_study)
    { student_counter++; }

    ~Student() 
    {}

    // mutators
    void set_year_of_study(int year) { year_of_study = year; }
    void update_year_of_study(int change) { assert(change >= 0); year_of_study += change; }

    // accessors
    int get_year_of_study() const { return year_of_study; }
    std::string get_info() const;
    static int get_number_of_students() { return student_counter; }
};

int Student::student_counter = 0;

std::string Student::get_info() const
{
    std::stringstream result(Person::get_info(), std::ios_base::app | std::ios_base::out);
    result << "Year of study: " << year_of_study << "\n";
    return result.str();
}

int main()
{
    Student ivan("Ivan", 18, MALE, 75.5, 1);
    Student maria("Maria", 19, FEMALE, 58.3, 2);

    std::cout << "You have " << Student::get_number_of_students() << " students\n\n";
    std::cout << "Here is information about them:\n";
    std::cout << ivan.get_info() << std::endl;
    std::cout << maria.get_info() << std::endl;
    
    return 0;
}