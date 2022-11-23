/**
 * Добавить в контейнерный класс, который был написан в этом уроке, методы: 
 * • для удаления последнего элемента массива (аналог функции pop_back() в векторах)
 * • для удаления первого элемента массива (аналог pop_front() в векторах)
 * • для сортировки массива
 * • для вывода на экран элементов.
*/
#include <iostream>
#include <cstdlib>
#include <cassert>

class ArrayInt
{
public:
    ArrayInt()
    : m_capacity(1), m_size(0), m_data(nullptr)
    {}

    ArrayInt(int length)
    {
        assert(length >= 0);
        
        m_size = 0;
        if (length > 0) {
            m_capacity = length;
            m_data = new int[length];
        } else {
            m_capacity = 1;
            m_data = nullptr;
        }
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    // access functions
    int size() const { return m_size; }
    const int& operator[](int index) const;
    void print() const;
    bool is_empty() const { return m_size == 0; }

    // modification functions
    void erase();
    int& operator[](int index);
    void resize(int new_length);
    void push_back(int value);
    int pop_front();
    int pop_back();
    void sort();
private:
    int m_capacity;
    int m_size;
    int* m_data;
};

void ArrayInt::print() const
{
    std::cout << "[";
    for (int i = 0; i < m_size; ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << m_data[i];
    }
    std::cout << "]\n";
}

const int& ArrayInt::operator[](int index) const
{
    assert(index >= 0 && index < m_size);
    return m_data[index];
}

int& ArrayInt::operator[](int index)
{
    assert(index >= 0 && index < m_capacity);
    return m_data[index];
}

void ArrayInt::erase()
{
    m_size = 0;
    delete[] m_data;
    m_data = nullptr;
}

void ArrayInt::resize(int new_length)
{
    if (new_length <= 0) {
        erase();
        return;
    }

    m_size = m_size < new_length ? m_size : new_length;
    m_capacity = new_length;
    int* new_array = new int[m_capacity];

    for (int i = 0; i < m_size; i++) {
        new_array[i] = m_data[i];
    }

    delete[] m_data;
    m_data = new_array;
}

void ArrayInt::push_back(int value)
{
    if (m_size >= m_capacity - 1) {
        resize(m_capacity * 2);
    }
    m_data[m_size++] = value;
}

int ArrayInt::pop_back()
{
    assert(m_size > 0);
    return m_data[m_size--];
}

int ArrayInt::pop_front()
{
    assert(m_size > 0);
    int temp = m_data[0];
    for (int i = 1; i < m_size; ++i) {
        m_data[i - 1] = m_data[i];
    }
    --m_size;
    return temp;
}

void ArrayInt::sort()
{
    int i, j;

    for (i = 1; i < m_size; ++i) {
        int temp = m_data[i];
        j = i;
        while (m_data[j - 1] > temp && j > 0) {
            m_data[j] = m_data[j - 1];
            --j;
        }
        m_data[j] = temp;
    }
}
int main()
{
    ArrayInt arr;
    
    for (int i = 0; i < 10; ++i) {
        arr.push_back(rand() % 20);
    }

    arr.print();
    arr.sort();
    arr.print();

    arr.pop_front();
    arr.print();

    arr.pop_back();
    arr.print();

    return 0;
}