#ifndef MAP_H
#define MAP_H

#include <redblacktree.h>

template <typename KeyT, typename ValueT>
class Map : public RedBlackTree<KeyT, ValueT>
{
    using RedBlackTree = RedBlackTree<KeyT, ValueT>;
public:
    RedBlackTree::Node* Insert(KeyT key, ValueT value)
    {
        return RedBlackTree::Insert(key, value);
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

    ValueT& operator[](const KeyT key) {
        auto t = RedBlackTree::Search(key);
        if (t) {
            return RedBlackTree::Search(key)->value;
        }
        return RedBlackTree::Insert(key, ValueT())->value;
    }
};

#endif // MAP_H
