#include <iostream>
#include <algorithm>

#include "queue.h"


Queue::Queue(size_t size) : _size(size)
{
    arr = new ADT*[_size];
    for (size_t i = 0; i < _size; ++i) 
    {
        arr[i] = new ADT;
    }
    _quantity = 0;
}

Queue::Queue(const Queue &right) 
{
    if (arr != nullptr)
    {
        for (size_t i = 0; i < this->_size; ++i) delete [] arr[i];
        delete [] arr;
        arr = nullptr;
    }
    try 
    {
        this->_size = right._size;
        this->_quantity = right._quantity;
        this->arr = new ADT* [this->_size];
        for (size_t i = 0; i < _quantity; ++i)
        {
            arr[i] = new ADT;
            arr[i] = right.arr[i];
        }
    }
    catch (...) 
    {
        std::runtime_error("Error memory allocated");
        exit(1);
    }
}

Queue::~Queue()
{
    if (arr != nullptr)
    {
        for (size_t i = 0; i < this->_size; ++i) delete arr[i];
        delete [] arr;
    }
    
}

size_t Queue::size() const { return this->_quantity; }


void Queue::resize(size_t new_size)
{
    ADT **new_arr;
    try 
    {
        new_arr = new ADT*[new_size];
        for (size_t i = 0; i < this->_quantity; ++i ) 
        {
            new_arr[i] = new ADT;
            new_arr[i] = arr[i];
        }
    }
    catch (...) 
    {
        std::runtime_error("Error memory allocated");
        exit(1);
    }
    for (size_t i = 0; i < _size; ++i) delete [] arr[i];
    delete [] arr;
    arr = new_arr;
    this->_size = new_size;
    
}


ADT* Queue::pop_back()
{
    if (arr != nullptr && _quantity > 0)
    {
        ADT *val = arr[_quantity-1];
        --_quantity;
        return val;
    }
    else return nullptr;
}

void Queue::push_front(ADT *value)
{
    this->insert(0, value);
}

void Queue::emplace(size_t pos, ADT *value)
{
    arr[pos] = value;
}

void Queue::insert(size_t pos, ADT *value)
{
    if (empty())
    {
        arr[0] = value;
        ++_quantity;
    }
    else if (_quantity < _size)
    {
        ++_quantity;
        ADT *var = arr[pos];
        arr[pos] = value;
        ADT *qwa;
        for (size_t i = pos+1; i < _quantity; ++i)
        {
            qwa = arr[i];
            arr[i] = var;
            var = qwa;
        }
    }
    else if (_quantity == _size)
    {

        for (size_t i = 0; i < pos; ++i)
            arr[i+1] = arr[i];
        arr[0] = arr[_quantity-1];
        ADT *var = arr[pos];
        arr[pos] = value;
        ADT *qwa;
        for (size_t i = pos+1; i < _quantity; ++i)
        {
            qwa = arr[i];
            arr[i] = var;
            var = qwa;
        }
    }
}
   

void Queue::erase(size_t pos)
{
    --_quantity;
    for (size_t i = pos; i < _quantity; ++i) 
        arr[i] = arr[i+1];
}

void Queue::clear()
{
    delete [] arr;
    arr = nullptr;
    _size = 0;
    _quantity = 0;
}
bool Queue::empty() const { return _quantity == 0; }

//const Queue &Queue::operator= (const ADT &right)

const Queue &Queue::operator= (const Queue& right)
{
    if (_size != right._size) 
    {
        this->_quantity = right._quantity;
        if (arr != nullptr)
        {
            for (size_t i = 0; i < this->_size; ++i) delete [] arr[i];
            delete [] arr;
            arr = nullptr;
        }
        this->_size = right._size;
        try 
        {
            this->arr = new ADT* [right._size];
            for (size_t i = 0; i < right._quantity; ++i)
            {
                arr[i] = new ADT;
            }
        }
        catch (...) 
        {
            std::runtime_error("Error memory allocated");
            exit(1);
        }
    }
    for ( size_t i = 0; i < right._quantity; ++i )
        arr[i] = right.arr[i];
    return *this;
}
ADT* &Queue::operator[](size_t pos) { return arr[pos]; }
ADT* &Queue::begin() { return *arr; }
ADT* &Queue::end() { return *(arr + _quantity); }

