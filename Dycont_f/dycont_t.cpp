#ifndef dycont_t_h
#define dycont_t_h

#include <iostream>
#include <algorithm>
#include <iterator>

#include "ADT.h"



template <typename T>
class Dycont_t
{

    
    private:

        const static size_t CAP_ADD = 5;

        size_t _size;
        size_t _capacity;
        T *arr = nullptr;

        void set_capacity(size_t new_size);

    public:
        template <typename>
        class Iterator;
        template <typename>
        class Const_iterator;
        //Dycont_t<T>::Iterator<T> Dycont_t<T>::
        //typename Dycont_t<T>::Iterator;
        Iterator<T> begin();
        Iterator<T> end();
        Const_iterator<T> begin() const;
        Const_iterator<T> end() const;
        
        
        Dycont_t();
        Dycont_t(size_t size);
        Dycont_t(std::initializer_list<T> values);
        Dycont_t(const Dycont_t<T> &right); 
        ~Dycont_t();

        size_t capacity() const;
        size_t size() const;
        void resize(size_t new_size);
        void push_back(T right);
        void pop_back();
        void emplace(size_t pos, T value);
        void erase(size_t pos);
        void insert(size_t pos, T value);
        void clear();
        bool empty() const;

        const Dycont_t &operator= (const Dycont_t<T> &right);
        T &operator[](size_t pos);
        const T &operator[](Iterator<T> pos) const { return *pos.ptr; }

        template <typename > 
        class Iterator : public std::iterator<std::input_iterator_tag, T>
        {
            public:
                T *ptr;

                Iterator() : ptr(nullptr) {}
                Iterator(T *ptr) : ptr(ptr) {}

                Iterator(const Iterator &right) : ptr(right.ptr) {}

                T &operator*() const { return *ptr; }
                T &operator[](size_t pos) const { return ptr[pos]; }
                //T *operator->() const { return ptr->data; }
                bool operator!=(const Iterator<T> &right) {return ptr != right.ptr; }
                bool operator==(const Iterator<T> &right) {return ptr == right.ptr; }
                bool operator<(const Iterator<T> &right)  {return ptr < right.ptr; }
                Iterator operator+(const Iterator<T> &right) const { return this->ptr + right.ptr; }
                Iterator operator+(int right) const { return Iterator(this->ptr + right); }
                Iterator operator-(const Iterator<T> &right) const { return this->ptr - right.ptr; }
                Iterator operator-(int right) const { return Iterator(this->ptr - right); }
                
                Iterator &operator++() {++ptr; return *this; }
                Iterator operator++(int) {T *var_ptr = this->ptr; ++ptr; return *var_ptr; }
                Iterator &operator--() {--ptr; return *this; }
                Iterator operator--(int) {T *var_ptr = this->ptr; --ptr; return *var_ptr; }
        };

        template <typename>
        class Const_iterator : public std::iterator<std::input_iterator_tag, T>
        {
            public:
                T *ptr;

                Const_iterator() : ptr(nullptr) {}
                Const_iterator(T *ptr) : ptr(ptr) {}

                Const_iterator(const Const_iterator &right) : ptr(right.ptr) {}

                const T &operator*() const { return *ptr; }
                const T &operator[](size_t pos) const { return ptr[pos]; }
                //T *operator->() const { return ptr->data; }
                bool operator!=(const Const_iterator &right) const {return ptr != right.ptr;}
                bool operator==(const Const_iterator &right) const {return ptr == right.ptr;}
                Const_iterator operator+(const Const_iterator<T> &right) const { return this->ptr + right.ptr; }
                Const_iterator operator+(int right) const { return Const_iterator(this->ptr + right); }
                Const_iterator operator-(const Const_iterator<T> &right) const { return this->ptr - right.ptr; }
                Const_iterator operator-(int right) const { return Const_iterator(this->ptr - right); }
                Const_iterator &operator++() {++ptr; return *this; }
                Const_iterator operator++(int) {T *var_ptr = this->ptr; ++ptr; return *var_ptr; }
                Const_iterator &operator--() {--ptr; return *this; }
                Const_iterator operator--(int) {T *var_ptr = this->ptr; --ptr; return *var_ptr; }
        };

};


template <typename T>
void Dycont_t<T>::set_capacity(size_t new_size)
{
    if (new_size) this->_capacity = (new_size * 3) / 2 + 1;
    else this->_capacity = (_size * 3) / 2 + 1;
}

template <typename T>
Dycont_t<T>::Dycont_t() : _size(0), _capacity(0)  { arr = nullptr; }


template <typename T>
Dycont_t<T>::Dycont_t(std::initializer_list<T> values)
{
    _size = values.size();
    set_capacity(_size);
    arr = new T[_capacity];
    for (auto i = values.begin(); i < values.end();++i)
    {
        arr[i] = values[i];
    }
}

template <typename T>
Dycont_t<T>::Dycont_t(size_t size) : _size(size)
{
    if (_size < 0) std::runtime_error( "Error: length < 0");
    set_capacity(_size);
    arr = new T[_capacity];
}

template <typename T>
Dycont_t<T>::Dycont_t(const Dycont_t<T> &right) 
: _size(right._size), _capacity(right._capacity)
{
    this->arr = new T[this->_capacity];
    for (size_t i = 0; i < _size; ++i)
    {
        arr[i] = right.arr[i];
    }
}
template <typename T>
Dycont_t<T>::~Dycont_t()
{
    if (arr != nullptr)
    {
        delete [] arr;
        arr = nullptr;
    }
}


template <typename T>
size_t Dycont_t<T>::capacity() const { return this->_capacity; }
template <typename T>
size_t Dycont_t<T>::size() const { return this->_size; }

template <typename T>
void Dycont_t<T>::resize(size_t new_size)
{
    //this->_size = new_size;
    set_capacity(new_size);
    T *new_arr = new T[this->_capacity];
    for (size_t i = 0; i < _size; ++i ) new_arr[i] = arr[i];
    delete [] arr;
    arr = new_arr;
}

template <typename T>
void Dycont_t<T>::push_back(T value)
{
    if (_capacity == _size) resize(_size + 1);
    if (_size == 0 ) { arr[0] = value; ++_size; }
    else arr[_size++] = value;
}

template <typename T>
void Dycont_t<T>::pop_back()
{
    if (arr != nullptr && _size > 0) --_size;
}
template <typename T>
void Dycont_t<T>::emplace(size_t pos, T value)
{
    arr[pos] = value;
}

template <typename T>
void Dycont_t<T>::insert(size_t pos, T value)
{
    
    ++_size;
    if (_capacity == _size)
    {
        set_capacity(_size);
        T *new_arr = new T[this->_capacity];
        for (size_t i = 0; i < pos; ++i ) new_arr[i] = arr[i];
        for (size_t i = pos+1; i < _size; ++i ) new_arr[i] = arr[i-1];
        new_arr[pos] = value;
        delete [] arr;
        arr = new_arr;
    }
    else if (pos == _size)
    {
        --_size;
        return this->push_back(value);
    }
    else
    {
        T var = arr[pos];
        arr[pos] = value;
        T qwa;
        for (size_t i = pos+1; i < _size; ++i ) 
        {
            if (i < _size) qwa = arr[i];
            arr[i] = var;
            var = qwa;
        }
    }
}

template <typename T>
void Dycont_t<T>::erase(size_t pos)
{
    if (_size >= pos)
    {
        --_size;
        for (size_t i = pos; i < _size; ++i) arr[i] = arr[i+1];
    }
    else return;
}

template <typename T>
void Dycont_t<T>::clear()
{
    delete [] arr;
    arr = nullptr;
    _size = 0;
    _capacity = 0;
}
template <typename T>
bool Dycont_t<T>::empty() const { return _size == 0; }

//const Dycont_t &Dycont_t::operator= (const ADT &right)
template <typename T>
const Dycont_t<T> &Dycont_t<T>::operator= (const Dycont_t<T>& right)
{
    if (_capacity != right._capacity) 
    {
        this->_size = right._size;
        if (arr != nullptr)
        {
            delete [] arr;
            arr = nullptr;
        }
        this->_capacity = right._capacity;
        this->arr = new T[right._capacity];
    }
    for ( Iterator<T> it = begin(); it < right.end(); ++it )
        arr[it] = right.arr[it];
    return *this;
}

template <typename T>
T &Dycont_t<T>::operator[](size_t pos) { return arr[pos]; }

template <typename T>
Dycont_t<T>::Iterator<T> Dycont_t<T>::begin()
{
    return Iterator<T>(arr);
}
template <typename T>
Dycont_t<T>::Iterator<T> Dycont_t<T>::end()
{
    return Iterator<T>(arr + this->_size);
}

template <typename T>
Dycont_t<T>::Const_iterator<T> Dycont_t<T>::begin() const
{
    return Const_iterator<T>(arr[0]);
}
template <typename T>
Dycont_t<T>::Const_iterator<T> Dycont_t<T>::end() const
{
    return Const_iterator<T>(arr[this->_size]);
}

#endif // dycont_t_h

int main(int argc, char **argv)
{
    //::testing::InitGoogleTest(&argc, argv);
    Dycont_t<int> mass(5);
    mass[0] = 0;
    mass[1] = 1;
    mass[2] = 2;
    mass[3] = 3;
    mass[4] = 4;
    mass[5] = 5;
    mass.push_back(6);
    mass.erase(1);

    for (Dycont_t<int>::Iterator<int> it = mass.begin(); it < mass.end(); ++it)
        std::cout << mass[it] << '\n';
    //return RUN_ALL_TESTS();
}
