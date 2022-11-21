/**
 * Дан вектор чисел, требуется выяснить, сколько среди них различных.
 * Постараться использовать максимально быстрый алгоритм.
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>

int number_of_different(std::vector<int>& v)
{
    std::set<int> diff(v.begin(), v.end());
    return diff.size();
}

void print_vec(std::vector<int> v) {
    std::cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << v[i];
    }
    std::cout << "]" << std::endl;
}


int main()
{
    std::vector<int> v;
    for (int i = 0; i < 20; ++i) {
        v.push_back(rand() % 15);
    }
    
    print_vec(v);
    std::cout << number_of_different(v) << std::endl;
}