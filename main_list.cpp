#include <iostream>

#include "list_t.hpp"

int main()
{
    int x = 10;
    List_t<int> mass;
    mass.push_back(x);
    mass.push_back(x);
    mass.push_back(x);
    mass.push_front(999);
    int y = 99;
    mass.insert(1, y);
    //mass.erase(2);
    //mass.pop_front();
    //mass.emplace(0, 100);

    for (Iterator<int> it = mass.begin(); it < mass.end(); ++it)
    //for(size_t i =0; i < mass.size(); ++i) // work
        std::cout << mass[it]/*->data*/ << '\n'; // errors: 72,253,258,307
}