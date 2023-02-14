#ifndef queue_h
#define queue_h

#include "ADT.h"

class Queue
{
    private:

        size_t _size;    // размер очереди
        size_t _quantity;// количество элементов
        ADT** arr;

        void resize(size_t new_size);

    public:

        Queue() = delete;
        Queue(size_t size);
        Queue(const Queue &right); 
        ~Queue();

        size_t size() const;
        ADT* pop_back();
        void push_front(ADT *value);
        void erase(size_t pos);
        void emplace(size_t, ADT*);
        void insert(size_t pos, ADT *value);
        void clear();
        bool empty() const;

        const Queue &operator= (const Queue &right);
        ADT* &operator[](size_t pos);
        ADT* &begin(); // first
        ADT* &end();   // last

};

#endif // queue_h
