/**
 * Написать класс, который реализует функциональность стека. 
*/
#include <iostream>

class Stack
{
private:
    int arr[10];
    int top = -1;
    bool is_full()
    {
        return (top == 9);
    }
public:
    void reset();
    bool push(int value);
    int pop();
    void print();
    int size();
    bool is_empty();
};

void Stack::reset()
{
    top = -1;
}

bool Stack::push(int value)
{
    if (is_full()) {
        return false;
    }
    arr[++top] = value;
    return true;
}

// вопрос, что здесь возвращать если стек пуст? выкидывать исключение?
int Stack::pop() 
{
    return arr[top--];
}

// да, не совсем по ТЗ, но так красивее :)
void Stack::print()
{
    std::cout << "[";
    for (int i = 0; i <= top; ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << arr[i];
    }
    std::cout << "]" << std::endl;
}

int Stack::size() 
{
    return top + 1;
}

bool Stack::is_empty()
{
    return top == -1;
}

int main()
{
    Stack stack;

    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}