#include "tree.h"

Tree::Tree() : tree(0), _size(0) {}
Tree::~Tree()
{
    if (tree != nullptr) delete_tree(this->tree);
}

void Tree::insert(const size_t pos, const ADT *data)
{
    Tnode *var = new Tnode(data, pos);
    Tnode *p1;
    Tnode *p2;
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
void Tree::erase(const size_t pos)
{
    Tnode *p1;
    Tnode *p2;
    Tnode *var = this->find(this->tree, pos);
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

const bool Tree::empty() const 
{
    return this->_size == 0;
}

const size_t Tree::size() const
{
    return _size;
}

Tree::Tnode *Tree::get_tree()
{
    return tree;
}

void Tree::print(Tnode *tree, std::ostream &out) const 
{
    if (tree != nullptr)
    {
        print(tree->left, out);
        out << *(tree->data) << std::endl;
        print(tree->right, out);
    }
}

const ADT *Tree::operator[](const size_t pos) const
{
    Tnode *var = find(this->tree, pos);
    if (var == nullptr) 
    {
        std::runtime_error("Not real");
        exit(1);
    }
    return var->data;
}

Tree::Tnode *Tree::find(Tnode *tree, const size_t pos) const
{
    if (tree == nullptr || pos == tree->pos) return tree;
    if (pos % 2 == 0) return find(tree->right, pos);
    else return find(tree->left, pos);
}


Tree::Tnode *Tree::find_C(const size_t pos) const
{
    Tnode *p1 = find(tree, pos);
    Tnode *p2;
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

void Tree::delete_tree(Tnode* tree)
{
    if (tree != nullptr)
    {
        delete_tree(tree->left);
        delete tree;
        delete_tree(tree->right);
    }
    tree = nullptr;
}


/*

Tree::Tnode* Tree::add_node(Tnode *tree, ADT* data, size_t pos, size_t add = 0, size_t level = 0) 
{
    if (1)//(data == nullptr && tree->pos != pos)
    {
        if (pos - (2 << level) <= (2 << level))
        {
            tree =new Tnode;
            if ( data != nullptr ) tree->data = new ADT(*data);   
            tree->left =  nullptr;
            tree->right = nullptr;
            tree->pos = (2 << level) + add;
            //++tree->level;
            
            tree->level = level;
            //return tree;
        }
        size_t hight = 0;
        while (pos > (2 << hight)) ++hight;
        --hight;
        if (pos % 2 == 0)
            return tree->left = add_node(tree->left, nullptr, pos - pos/2, pos - (2 << hight), (hight)); // if ( tree->pos != 0 )
        else
            return tree->right = add_node(tree->left, nullptr, pos - pos/2 + 1 , pos- (2 << hight), (hight));
    }
    else 
    {
        tree =new Tnode;
        tree->data = new ADT(*data);   
        tree->left =  nullptr;
        tree->right = nullptr;
        tree->pos = pos;
        return tree;
    }
}
    if (tree == nullptr && pos == 1) // если дерева нет, то делаем корень
    { 
        tree =new Tnode;
        if ( data != nullptr ) tree->data = new ADT(*data);   
        tree->left =  nullptr;
        tree->right = nullptr;
        if ( tree->pos != 0 ) tree->pos = (2 << tree->level) + pos;
        ++tree->level;
    }
    else if (pos % 2 == 1)   // добавление левого потомка
    {
        size_t hight = 0;
        while (pos > (2 << hight)) ++hight;
        --hight;
        if (tree->pos != pos)
            tree->left = add_node(tree->left, nullptr, tree->pos - (2 << hight));
        else
            tree->left = add_node(tree->left, data, pos);
    }
    else                              // добавление правого потомка
        tree->right = add_node(tree->right, data);
    return tree;
}
*/
