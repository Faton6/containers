#ifndef tree_t_h
#define tree_t_h

#include "ADT.h"



template <typename T>
class Tree_t
{
    private:
        template <typename>
        struct Tnode 
        {
                T data;    // поле данных
                size_t pos;         // префиксная позиция в дереве (иначе говоря ключ)
                Tnode<T> *left;        // левый потомок
                Tnode<T> *right;       // правый потомок
                Tnode<T> *parent;      // родитель
                Tnode() : data(0), pos(0), left(nullptr), right(nullptr) {}
                Tnode(const T data, const size_t pos = 0)
                {
                    this->data = data;
                    this->pos = pos;
                    this->left = nullptr;
                    this->right = nullptr;
                }
                ~Tnode() = default;
        };
        
        Tnode<T> *find(Tnode<T> *tree, const size_t pos) const; // находит элемент, с заданной позицией
        Tnode<T> *find_C(const size_t pos) const; // находит элемент с ключем, следующим за данным числом
        void delete_tree(Tnode<T>* tree); // очистка памяти
        Tnode<T> *tree;
        size_t _size;
        
    public:

        Tree_t();
        ~Tree_t();
        void insert(const size_t pos, const T data);
        void erase(const size_t pos);       
        void print(Tnode<T> *tree, std::ostream &out) const;
        const bool empty() const;
        const size_t size() const;
        Tnode<T> *get_tree();
        const T &operator[](const size_t pos) const;
        
};
template <typename T>
Tree_t<T>::Tree_t() : tree(0), _size(0) {}

template <typename T>
Tree_t<T>::~Tree_t()
{
    if (tree != nullptr) delete_tree(this->tree);
}

template <typename T>
void Tree_t<T>::insert(const size_t pos, const T data)
{
    Tnode<T> *var = new Tnode<T>(data, pos);
    Tnode<T> *p1;
    Tnode<T> *p2;
    p1 = tree;
    do
    {
        p2 = p1;
        if (p1 != nullptr && pos % 2 == 1) p1 = p1->left;
        else if (p1 != nullptr) p1 = p1->right;
    }while (p1 != nullptr);

    var->parent = p2;
    if (p2 == nullptr) tree = var;
    else
    {
        if ( pos %2==1  ) p2->left = var;
        else p2->right = var;
    }
    ++_size;
}

template <typename T>
void Tree_t<T>::erase(const size_t pos)
{
    Tnode<T> *p1;
    Tnode<T> *p2;
    Tnode<T> *var = this->find(this->tree, pos);
    if (var->left == nullptr || var->right == nullptr) p1 = var;
    else p1 = find_C(var->pos);

    if (p1->left != nullptr) p2 = p1->left;
    else p2 = p1->right;

    if (p2 != nullptr) p2->parent = p1->parent;

    if (p1->parent == nullptr) tree = p2;
    else
    {
        if (p1 == (p1->parent)->left) (p1->parent)->left = p2;
        else (p1->parent)->right = p2;
    }
    --_size;
}

template <typename T>
const bool Tree_t<T>::empty() const 
{
    return this->_size == 0;
}

template <typename T>
const size_t Tree_t<T>::size() const
{
    return _size;
}

template <typename T>
Tree_t<T>::Tnode<T> *Tree_t<T>::get_tree()
{
    return tree;
}

template <typename T>
void Tree_t<T>::print(Tnode<T> *tree, std::ostream &out) const 
{
    if (tree != nullptr)
    {
        print(tree->left, out);
        out << *(tree->data) << std::endl;
        print(tree->right, out);
    }
}

template <typename T>
const T &Tree_t<T>::operator[](const size_t pos) const
{
    Tnode<T> *var = find(this->tree, pos);
    if (var == nullptr) 
    {
        std::runtime_error("Not real");
        exit(1);
    }
    return var->data;
}

template <typename T>
Tree_t<T>::Tnode<T> *Tree_t<T>::find(Tnode<T> *tree, const size_t pos) const
{
    if (tree == nullptr || pos == tree->pos) return tree;
    if (pos % 2 == 0) return find(tree->right, pos);
    else return find(tree->left, pos);
}

template <typename T>
Tree_t<T>::Tnode<T> *Tree_t<T>::find_C(const size_t pos) const
{
    Tnode<T> *p1 = find(tree, pos);
    Tnode<T> *p2;
    if ( p1 == nullptr ) return nullptr;
    if (p1->right != nullptr)
    {
        while (p1->left != nullptr)
        {
            p1 = p1->left;
        }
        return p1;
    }
    p2 = p1->parent;
    while (p2 != nullptr && p1 == p2->right)
    {
        p1 = p2;
        p2 = p2->parent;
    }
    return p2;

}

template <typename T>
void Tree_t<T>::delete_tree(Tnode<T>* tree)
{
    if (tree != nullptr)
    {
        delete_tree(tree->left);
        delete tree;
        delete_tree(tree->right);
    }
    tree = nullptr;
}


#endif // tree_t_h