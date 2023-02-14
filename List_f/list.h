#ifndef list_h
#define list_h

#include <iostream>

#include "ADT.h"

class List 
{
    
private:
    // Структура узла односвязного списка
    struct Node 
    { 
        // Значение узла
        const ADT *data;
        
        // Указатель на следующий узел
        Node *next;

        Node() : next(nullptr){}
 
        Node(const ADT *obj ) : data(obj), next(nullptr) {}

    };
 
    Node *first;
    Node *last;
    size_t _size;

public:

    List() : first(nullptr), last(nullptr), _size(0) {}
    List(size_t size); // наверное лучше убрать
    ~List();

    void push_back(const ADT *right);
    void push_front(const ADT *right);
    void pop_back();
    void pop_front();

    void erase(size_t pos);
    void insert(size_t pos, const ADT *value);
    void emplace(size_t pos, const ADT *obj);

    size_t size() const;
    void clear();
    bool empty() const;

    Node* &operator[](size_t pos);
    const Node* operator[](size_t pos) const;
};

#endif // list_h
