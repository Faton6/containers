#ifndef stack_h
#define stack_h

#include <iostream>

#include "ADT.h"

class Stack
{
    private:
        const static size_t CAP_ADD = 5;

        size_t _size;
        size_t _capacity;
        ADT** arr;

        void set_capacity(size_t new_size);

    public:

        Stack();
        Stack(size_t size);
        Stack(const Stack &right); 
        ~Stack();

        size_t capacity() const;
        size_t size() const;
        void resize(size_t new_size);
        void push_back(ADT *right);
        void pop_back();
        void push_front(ADT *value);
        void pop_front();
        void emplace(size_t pos, ADT *value);
        void erase(size_t pos);
        void insert(size_t pos, ADT *value);
        void clear();
        bool empty() const;


        const Stack &operator= (const Stack &right);
        ADT* &operator[](size_t pos);
        ADT* &begin();
        ADT* &end();
};

#endif // stack_h
