#ifndef list_t_h
#define list_t_h

#include <iostream>
#include <algorithm>
#include <iterator>

#include "ADT.h"

template <typename T>
class List_t
{
        
    private:
        // Структура узла односвязного списка
        template <typename>
        struct Node 
        { 
            // Значение узла
            const T data;
            
            // Указатель на следующий узел
            Node *next;

            Node() : next(nullptr){}
    
            Node(const T obj ) : data(obj), next(nullptr) {}

        };
    
        Node<T> *first;
        Node<T> *last;
        size_t _size;

    public:

        template <typename>
        class Iterator;
        template <typename>
        class Const_iterator;

        List_t() : first(nullptr), last(nullptr), _size(0) {}
        List_t(size_t size); // наверное лучше убрать
        ~List_t();

        Iterator<T> begin();
        Iterator<T> end();
        Const_iterator<T> begin() const;
        Const_iterator<T> end() const;

        void push_back(const T right);
        void push_front(const T right);
        void pop_back();
        void pop_front();

        void erase(size_t pos);
        void insert(size_t pos, const T value);
        void emplace(size_t pos, const T obj);

        size_t size() const;
        void clear();
        bool empty() const;

        Node<T>* &operator[](size_t pos);
        const Node<T>* operator[](size_t pos) const;
        const T &operator[](Iterator<T> pos) const { return pos.ptr->data; }

        template <typename> 
        class Iterator : public std::iterator<std::input_iterator_tag, T>
        {
            public:

                Node<T> *ptr;

                Iterator() : ptr(nullptr) {}
                Iterator(Node<T> *ptr) : ptr(ptr) {}

                Iterator(const Iterator &right) : ptr(right.ptr) {}

                T &operator*() const { return ptr->data; }
                T &operator[](size_t pos) const { return ptr[pos]->data; }
                T *operator->() const { return ptr->data; }
                bool operator!=(const Iterator<T> &right) {return ptr != right.ptr; }
                bool operator==(const Iterator<T> &right) {return ptr == right.ptr; }
                bool operator<(const Iterator<T> &right)  {return ptr < right.ptr; }
                
                Iterator &operator++() { if (ptr != nullptr) ptr = ptr->next; return *this; }
                Iterator operator++(int) {T *var_ptr = this->ptr; ptr = ptr->next; return *var_ptr; }
                Iterator &operator--() {--ptr; return *this; }
                Iterator operator--(int) {T *var_ptr = this->ptr; --ptr; return *var_ptr; }
        };

        template <typename>
        class Const_iterator : public std::iterator<std::input_iterator_tag, T>
        {
            public:
                Node<T> *ptr;

                Const_iterator() : ptr(nullptr) {}
                Const_iterator(Node<T> *ptr) : ptr(ptr) {}

                Const_iterator(const Const_iterator &right) : ptr(right.ptr) {}

                const T &operator*() const { return ptr->data; }
                const T &operator[](size_t pos) const { return ptr[pos]->data; }
                const T *operator->() const { return ptr->data; }
                bool operator!=(const Const_iterator &right) const {return ptr != right.ptr;}
                bool operator==(const Const_iterator &right) const {return ptr == right.ptr;}
                bool operator<(const Iterator<T> &right)  {return ptr < right.ptr; }
                
                Const_iterator &operator++() {if (ptr != nullptr) ptr = ptr->next; return *this; }
                Const_iterator operator++(int) {T *var_ptr = this->ptr; ++ptr; return *var_ptr; }
                Const_iterator &operator--() {--ptr; return *this; }
                Const_iterator operator--(int) {T *var_ptr = this->ptr; --ptr; return *var_ptr; }
        };

};

template <typename T>
List_t<T>::List_t(size_t size)
{
    Node<T> *var = new Node<T>;
    first = var;
    last = var;
    for (size_t i = 1; i < size-1; ++i)
    {
        Node<T> *next = new Node<T>;
        last->next = next;
        last = next;
    }    
    _size = size;
}

template <typename T>
List_t<T>::~List_t()
{
    if (empty()) return;
    Node<T> *var = first;
    if (var) return;
    else {
        while (var->next != last) 
        {
            delete var;
            var = var->next;
            if (!var) return;
        }
        delete var;
    }
}


template <typename T>
void List_t<T>::push_back(const T obj) 
{
    Node<T> *var = new Node<T>(obj);
    if (empty()) 
    {
        first = var;
        last = var;
        ++_size;
        return;
    }
    last->next = var;
    last = var;
    ++_size;
}

template <typename T>
void List_t<T>::push_front(const T obj)
{
    Node<T> *var = new Node<T>(obj);
    var->next = first;
    first = var;
    ++_size;
}


template <typename T>
void List_t<T>::pop_front() 
{
    if (empty()) return;
    --_size;
    Node<T> *val = first;
    first = first->next;
    delete val;
}

template <typename T>
void List_t<T>::pop_back() 
{
    if (empty()) return;
    if (first == last) 
    {
        pop_front();
        return;
    }
    Node<T>* val = first;
    while (val->next != last) val = val->next;
    val->next = nullptr;
    delete last;
    last = val;
    --_size;
}


template <typename T>
void List_t<T>::erase(size_t pos)
{
    if (pos == 1) return pop_front();
    if (empty()) return;
    --_size;
    Node<T> *var = first;
    for (size_t i = 1; i < pos-1; ++i) 
    {
        var = var->next;
        if (!var) return;
    }

    Node<T> *temp = var->next;
    var->next = temp->next;

}

template <typename T>
void List_t<T>::insert(size_t pos, const T value)
{
    if (pos > _size) std::runtime_error("Position more size");
    if (empty()) return push_back(value);
    ++_size;
    Node<T> *var = first;
    for (size_t i = 1; i < pos-1; ++i) 
    {
        var = var->next;
        if (!var) return;
    }
    Node<T> *temp = var->next;
    Node<T> *qwa = new Node<T>(value);
    var->next = qwa;
    qwa->next = temp;
}

template <typename T>
void List_t<T>::emplace(size_t pos, const T obj)
{
    if (empty()) return;
    if (pos > _size) std::runtime_error("Position more size");
    Node<T> *var = first;
    for (size_t i = 0; i < pos-1; ++i) 
    {
        var = var->next;
        if (!var) return;
    }
    var->data = obj;
}


template <typename T>
size_t List_t<T>::size() const { return _size; }

template <typename T>
void List_t<T>::clear()
{    
    if (empty()) return;
    Node<T> *var = first;
    if (var) return;
    else {
        while (var->next != last) 
        {
            delete var;
            var = var->next;
            if (!var) return;
        }
        delete var;
    }
    _size = 0;
}

template <typename T>
bool List_t<T>::empty() const { return _size == 0; }


template <typename T>
List_t<T>::Node<T>* &List_t<T>::operator[](size_t pos) 
{
    Node<T>* var = this->first;
    for (size_t i = 0; i < pos; ++i) 
    {
        if (var->next != nullptr) var = var->next;
    }
    Node<T>* &ref = var;
    return ref;
}

template <typename T>
List_t<T>::Iterator<T> List_t<T>::begin()
{
    return Iterator<T>(first);
}
template <typename T>
List_t<T>::Iterator<T> List_t<T>::end()
{
    return Iterator<T>(last);
}

template <typename T>
List_t<T>::Const_iterator<T> List_t<T>::begin() const
{
    return Const_iterator<T>(first);
}
template <typename T>
List_t<T>::Const_iterator<T> List_t<T>::end() const
{
    return Const_iterator<T>(last);
}

/*
template <typename T>
const List_t<T>::Node<T>* List_t<T>::operator[](size_t pos) const
{
    Node<T>* var = this->first;
    for (size_t i = 0; i < pos; ++i) 
    {
        if (var->next != nullptr) var = var->next;
        else if (i < pos) std::runtime_error("Error of position");
    }
    return var;
}
*/


#endif // list_t_h
