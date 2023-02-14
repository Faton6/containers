#include <iostream>

#include "stack_t.hpp"

int main()
{
    int x = 10;
    Stack_t<int> mass;
    mass.push_back(x);
    mass.push_back(x);
    mass.push_back(x);
    mass.push_front(999);
    int y = 99;
    mass.insert(1, y);
    mass.erase(2);
    mass.pop_front();
    //mass.emplace(0, 100);
    for (Iterator<int> it = mass.begin(); it < mass.end(); ++it)
        std::cout << mass[it] << '\n';
}