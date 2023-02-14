#include <iostream>
#include <algorithm>

#include "stack.h"

void Stack::set_capacity(size_t new_size = 0)
{
    if (new_size) this->_capacity = (new_size * 3) / 2 + 1;
    else this->_capacity = (_size * 3) / 2 + 1;
}

Stack::Stack() : _size(0), _capacity(0)  { *arr = nullptr;}

Stack::Stack(size_t size) : _size(size)
{
    set_capacity();
    arr = new ADT*[_capacity];
    for (size_t i = 0; i < _size; ++i) 
    {
        arr[i] = new ADT;
    }
}

Stack::Stack(const Stack &right) 
: _size(right._size)
{
    if (arr != nullptr)
    {
        delete [] arr;
        arr = nullptr;
    }
    this->_capacity = right._capacity;
    try 
    {
        this->arr = new ADT* [this->_capacity];
        for (size_t i = 0; i < _size; ++i)
        {
            arr[i] = new ADT;
            arr[i] = right.arr[i];
        }
    }
    catch (...) 
    {
        std::runtime_error( "Error memory allocated" );
        exit(1);
    }
}

Stack::~Stack()
{
    if (arr != nullptr)
    {
        for (size_t i = 0; i < this->_capacity; ++i) delete arr[i];
        delete [] arr;
        arr = nullptr;
    }
    
}

size_t Stack::capacity() const { return this->_capacity; }
size_t Stack::size() const { return this->_size; }


void Stack::resize(size_t new_size)
{
    this->_size = new_size;
    size_t old_capacity = this->_capacity;
    set_capacity(new_size);
    ADT **new_arr;
    try 
    {
        new_arr = new ADT*[this->_capacity];
        for (size_t i = 0; i < this->_size; ++i ) 
        {
            new_arr[i] = new ADT;
            new_arr[i] = arr[i];
        }
    }
    catch (...) 
    {
        std::runtime_error( "Error memory allocated" );
        exit(1);
    }
    for (size_t i = 0; i < old_capacity; ++i) delete [] arr[i];
    delete [] arr;
    arr = new_arr;
}

void Stack::push_back(ADT *value)
{
    if (_capacity == _size) resize(_size + 1);
    arr[_size++] = value;
}
void Stack::pop_back()
{
    if (!empty()) --_size;
}

void Stack::push_front(ADT *value)
{
    this->insert(0, value);
}
void Stack::pop_front()
{
    if (empty()) return;
    this->erase(0);
}

void Stack::emplace(size_t pos, ADT *value)
{
    arr[pos] = value;
}

void Stack::insert(size_t pos, ADT *value)
{
    ++_size;
    if (_capacity == _size)
    {
        set_capacity();
        ADT **new_arr;
        try 
        {
            new_arr = new ADT*[this->_capacity];
            for (size_t i = 0; i < this->_size; ++i)
            {
                new_arr[i] = new ADT;
            }
        }
        catch (...) 
        {
            std::runtime_error( "Error memory allocated" );
            exit(1);
        }
        for (size_t i = 0; i < pos; ++i ) new_arr[i] = arr[i];
        for (size_t i = pos+1; i < _size; ++i ) new_arr[i] = arr[i-1];
        new_arr[pos] = value;
        delete [] arr;
        arr = new_arr;
    }
    else
    {
        ADT *var = arr[pos];
        arr[pos] = value;
        ADT *qwa;
        for (size_t i = pos+1; i < _size; ++i ) 
        {
            if (i < _size) qwa = arr[i];
            arr[i] = var;
            var = qwa;
        }
    }
}

void Stack::erase(size_t pos)
{
    --_size;
    for (size_t i = pos; i < _size; ++i) arr[i] = arr[i+1];
}

void Stack::clear()
{
    delete [] arr;
    arr = nullptr;
    _size = 0;
    _capacity = 0;
}
bool Stack::empty() const { return _size == 0; }
const Stack &Stack::operator= (const Stack &right)
{
    if (_capacity != right._capacity) 
    {
        this->_size = right._size;
        if (arr != nullptr)
        {
            for (size_t i = 0; i < this->_capacity; ++i) delete [] arr[i];
            delete [] arr;
            arr = nullptr;
        }
        this->_capacity = right._capacity;
        try 
        {
            this->arr = new ADT* [right._capacity];
            for (size_t i = 0; i < right._size; ++i)
            {
                arr[i] = new ADT;
            }
        }
        catch (...) 
        {
            std::runtime_error( "Error memory allocated" );
            exit(1);
        }
    }
    for ( size_t i = 0; i < right._size; ++i )
        arr[i] = right.arr[i];
    return *this;
}
ADT* &Stack::operator[](size_t pos) { return arr[pos]; }
ADT* &Stack::begin() { return *arr; }
ADT* &Stack::end() { return *(arr + _size); }




