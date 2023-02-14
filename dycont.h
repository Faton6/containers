#ifndef dy_mass_h
#define dy_mass_h

#include <iostream>

#include "ADT.h"

class Dycont
{
    private:

        const static size_t CAP_ADD = 5;

        size_t _size;
        size_t _capacity;
        ADT **arr;

        void set_capacity(size_t new_size);

    public:

        Dycont();
        Dycont(int size);
        Dycont(const Dycont &right); 
        ~Dycont();

        size_t capacity() const;
        size_t size() const;
        void resize(size_t new_size);
        void push_back(ADT *right);
        void pop_back();
        void emplace(size_t pos, ADT *value);
        void erase(size_t pos);
        void insert(size_t pos, ADT *value);
        void clear();
        bool empty() const;

        const Dycont &operator= (const Dycont &right);
        ADT* &operator[](size_t pos);
        ADT* &begin();
        ADT* &end();


};


#endif // dy_mass_h
