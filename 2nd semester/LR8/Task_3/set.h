#ifndef SET_H
#define SET_H

#include <redblacktree.h>

template <typename KeyT>
class Set : public RedBlackTree<KeyT, char>
{
    using RedBlackTree = RedBlackTree<KeyT, char>;
public:
    RedBlackTree::Node* Insert(KeyT key)
    {
        char c = '\0';
        return RedBlackTree::Insert(key, c);
    }
    RedBlackTree::Node* Find(KeyT key)
    {
        return RedBlackTree::Search(key);
    }
    void Erase(KeyT key)
    {
        RedBlackTree::Delete(key);
    }
    bool Empty() {
        return RedBlackTree::Size() == 0;
    }
};

#endif // SET_H
