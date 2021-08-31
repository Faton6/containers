#ifndef Queue_t_h
#define Queue_t_h

#include "ADT.h"


template <typename T>
class Queue_t
{
    private:

        size_t _size;    // размер очереди
        size_t _quantity;// количество элементов
        T* arr;

        void resize(size_t new_size);

    public:

        template <typename>
        class Iterator;
        template <typename>
        class Const_iterator;

        Queue_t() = delete;
        Queue_t(size_t size);
        Queue_t(const Queue_t &right); 
        ~Queue_t();

        Iterator<T> begin();
        Iterator<T> end();
        Const_iterator<T> begin() const;
        Const_iterator<T> end() const;
        size_t size() const;
        T pop_back();
        void push_front(T value);
        void erase(size_t pos);
        void emplace(size_t, T value);
        void insert(size_t pos, T value);
        void clear();
        bool empty() const;

        const Queue_t &operator= (const Queue_t &right);
        T &operator[](size_t pos);
        const T &operator[](Iterator<T> pos) const { return *pos.ptr; }

        template <typename> 
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
Queue_t<T>::Queue_t(size_t size) : _size(size)
{
    arr = new T[_size];
    _quantity = 0;
}

template <typename T>
Queue_t<T>::Queue_t(const Queue_t<T> &right) 
{
    if (arr != nullptr)
    {
        delete [] arr;
        arr = nullptr;
    }

    this->_size = right._size;
    this->_quantity = right._quantity;
    this->arr = new T[this->_size];
    for (size_t i = 0; i < _quantity; ++i)
    {
        arr[i] = right.arr[i];
    }

}

template <typename T>
Queue_t<T>::~Queue_t()
{
    if (arr != nullptr)
    {
        delete [] arr;
        arr = nullptr;
    }
    
}

template <typename T>
size_t Queue_t<T>::size() const { return this->_quantity; }


template <typename T>
void Queue_t<T>::resize(size_t new_size)
{
    T *new_arr;

    new_arr = new T[new_size];
    for (size_t i = 0; i < this->_quantity; ++i ) 
    {
        new_arr[i] = arr[i];
    }

    delete [] arr;
    arr = new_arr;
    this->_size = new_size;
    
}


template <typename T>
T Queue_t<T>::pop_back()
{
    if (arr != nullptr && _quantity > 0)
    {
        T val = arr[_quantity-1];
        --_quantity;
        return val;
    }
    else return nullptr;
}

template <typename T>
void Queue_t<T>::push_front(T value)
{
    this->insert(0, value);
}

template <typename T>
void Queue_t<T>::emplace(size_t pos, T value)
{
    arr[pos] = value;
}

template <typename T>
void Queue_t<T>::insert(size_t pos, T value)
{
    if (empty())
    {
        arr[0] = value;
        ++_quantity;
    }
    else if (_quantity < _size)
    {
        ++_quantity;
        T var = arr[pos];
        arr[pos] = value;
        T qwa;
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
        T var = arr[pos];
        arr[pos] = value;
        T qwa;
        for (size_t i = pos+1; i < _quantity; ++i)
        {
            qwa = arr[i];
            arr[i] = var;
            var = qwa;
        }
    }
}
   

template <typename T>
void Queue_t<T>::erase(size_t pos)
{
    --_quantity;
    for (size_t i = pos; i < _quantity; ++i) 
        arr[i] = arr[i+1];
}

template <typename T>
void Queue_t<T>::clear()
{
    delete [] arr;
    arr = nullptr;
    _size = 0;
    _quantity = 0;
}

template <typename T>
bool Queue_t<T>::empty() const { return _quantity == 0; }

template <typename T>
const Queue_t<T> &Queue_t<T>::operator= (const Queue_t<T>& right)
{
    if (_size != right._size) 
    {
        this->_quantity = right._quantity;
        if (arr != nullptr)
        {
            delete [] arr;
            arr = nullptr;
        }
        this->_size = right._size;
        this->arr = new T[right._size];
    }
    for ( size_t i = 0; i < right._quantity; ++i )
        arr[i] = right.arr[i];
    return *this;
}

template <typename T>
T &Queue_t<T>::operator[](size_t pos) { return arr[pos]; }


template <typename T>
Queue_t<T>::Iterator<T> Queue_t<T>::begin()
{
    return Iterator<T>(arr);
}
template <typename T>
Queue_t<T>::Iterator<T> Queue_t<T>::end()
{
    return Iterator<T>(arr + this->_size);
}

template <typename T>
Queue_t<T>::Const_iterator<T> Queue_t<T>::begin() const
{
    return Const_iterator<T>(arr[0]);
}
template <typename T>
Queue_t<T>::Const_iterator<T> Queue_t<T>::end() const
{
    return Const_iterator<T>(arr[this->_size]);
}



#endif // Queue_t_h
