#ifndef tree_h
#define tree_h

#include "ADT.h"

class Tree
{
    private:
    //public:
        struct Tnode 
        {
                const ADT *data;    // поле данных
                size_t pos;         // префиксная позиция в дереве (иначе говоря ключ)
                Tnode *left;        // левый потомок
                Tnode *right;       // правый потомок
                Tnode *parent;      // родитель
                Tnode() : data(nullptr), pos(0), left(nullptr), right(nullptr) {}
                Tnode(const ADT *data, const size_t pos = 0)
                {
                    this->data = data;
                    this->pos = pos;
                    this->left = nullptr;
                    this->right = nullptr;
                }
                ~Tnode() = default;
        };
        
        Tnode *find(Tnode *tree, const size_t pos) const; // находит элемент, с заданной позицией
        Tnode *find_C(const size_t pos) const; // находит элемент с ключем, следующим за данным числом
        void delete_tree(Tnode* tree); // очистка памяти
        Tnode *tree;
        size_t _size;
        
    public:

        Tree();
        ~Tree();
        void insert(const size_t pos, const ADT *data);
        void erase(const size_t pos);       
        void print(Tnode *tree, std::ostream &out) const;
        const bool empty() const;
        const size_t size() const;
        Tnode *get_tree();
        const ADT* operator[](const size_t pos) const;
        
};

#endif // tree_h