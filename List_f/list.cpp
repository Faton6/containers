#include "list.h"

List::List(size_t size)
{
    Node *var = new Node();
    first = var;
    last = var;
    for (size_t i = 1; i < size-1; ++i)
    {
        Node *next = new Node();
        last->next = next;
        last = next;
    }    
    _size = size;
}

List::~List()
{
    if (empty()) return;
    Node *var = first;
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


void List::push_back(const ADT *obj) 
{
    Node *var = new Node(obj);
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
void List::push_front(const ADT *obj)
{
    Node *var = new Node(obj);
    var->next = first;
    first = var;
    ++_size;
}


void List::pop_front() 
{
    if (empty()) return;
    --_size;
    Node* val = first;
    first = first->next;
    delete val;
}

void List::pop_back() 
{
    if (empty()) return;
    if (first == last) 
    {
        pop_front();
        return;
    }
    Node* val = first;
    while (val->next != last) val = val->next;
    val->next = nullptr;
    delete last;
    last = val;
    --_size;
}


void List::erase(size_t pos)
{
    if (pos == 1) return pop_front();
    if (empty()) return;
    --_size;
    Node *var = first;
    for (size_t i = 1; i < pos-1; ++i) 
    {
        var = var->next;
        if (!var) return;
    }

    Node *temp = var->next;
    //delete var->next;
    var->next = temp->next;

}

void List::insert(size_t pos, const ADT *value)
{
    if (pos > _size) std::runtime_error("Position more size");
    if (empty()) return push_back(value);
    ++_size;
    Node *var = first;
    for (size_t i = 1; i < pos-1; ++i) 
    {
        var = var->next;
        if (!var) return;
    }
    Node *temp = var->next;
    Node *qwa = new Node(value);
    var->next = qwa;
    qwa->next = temp;
}

void List::emplace(size_t pos, const ADT *obj)
{
    if (empty()) return;
    if (pos > _size) std::runtime_error("Position more size");
    Node *var = first;
    for (size_t i = 0; i < pos-1; ++i) 
    {
        var = var->next;
        if (!var) return;
    }
    var->data = obj;
}


size_t List::size() const { return _size; }

void List::clear()
{    
    if (empty()) return;
    Node *var = first;
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

bool List::empty() const { return _size == 0; }


List::Node* &List::operator[](size_t pos) 
{
    Node* var = this->first;
    for (size_t i = 0; i < pos; ++i) 
    {
        if (var->next != nullptr) var = var->next;
    }
    Node* &ref = var;
    return ref;
}

const List::Node* List::operator[](size_t pos) const
{
    Node* var = this->first;
    for (size_t i = 0; i < pos; ++i) 
    {
        if (var->next != nullptr) var = var->next;
        else if (i < pos) std::runtime_error("Error of position");
    }
    return var;
}
