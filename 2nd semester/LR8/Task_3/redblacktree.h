#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <utility>
#include <algorithm>
#include <QDebug>

template <typename KeyT, typename ValueT>
class RedBlackTree
{
public:
    struct Node {
        Node* parent = nullptr;
        Node* left = nullptr;
        Node* right = nullptr;
        bool color = 0; // 0 for black and 1 for red
        KeyT key;
        ValueT value;

        Node(Node& other) : parent(other.parent), left(other.left), right(other.right), color(other.color), key(other.key), value(other.value) {}
        Node(Node&& other) : parent(other.parent), left(other.left), right(other.right), color(other.color), key(other.key), value(other.value) {}
        Node(KeyT& key, ValueT& value) : key(key), value(value) {}
        Node(KeyT&& key, ValueT&& value) : key(std::move(key)), value(std::move(value)) {}
        Node(Node* parent, Node* left, Node* right, bool color, KeyT& key, ValueT& value) :
            parent(parent), left(left), right(right), color(color), key(key), value(value) {}
    };

    Node* root = nullptr;
public:
    RedBlackTree() {}

    Node* Grandparent(Node* node)
    {
        if (node && node->parent)
            return node->parent->parent;

        return nullptr;
    }

    Node* Uncle(Node* node)
    {
        if (Node* g = Grandparent(node)) {
            if (node->parent == g->left)
                return g->right;
            else
                return g->left;
        }

        return nullptr;
    }

    Node* Sibling(Node* node)
    {
        if (node && node->parent) {
            if (node == node->parent->left)
                return node->parent->right;
            else
                return node->parent->left;
        }

        return nullptr;
    }

    Node* CloseNephew(Node* node)
    {
        if (Node* s = Sibling(node)) {
            if (node == node->parent->left)
                return s->left;
            else
                return s->right;
        }
        return nullptr;
    }

    Node* DistantNephew(Node* node)
    {
        if (Node* s = Sibling(node)) {
            if (node == node->parent->left)
                return s->right;
            else
                return s->left;
        }
        return nullptr;
    }

    Node* Insert(KeyT& key, ValueT& value) {
        if (!root)
            return root = new Node(key, value);
        return Insert(key, value, root);
    }

    Node* Insert(KeyT& key, ValueT& value, Node* node)
    {
        if (key < node->key) {
            if (node->left)
                Insert(key, value, node->left);
            else {
                node->left = new Node(node, nullptr, nullptr, 1, key, value);
                FixInsert(node->left);
                while (root->parent)
                    root = root->parent;
                return node->left;
            }
        }

        if (key > node->key) {
            if (node->right)
                Insert(key, value, node->right);
            else {
                node->right = new Node(node, nullptr, nullptr, 1, key, value);
                FixInsert(node->right);
                while (root->parent)
                    root = root->parent;
                return node->right;
            }
        }

        if (key == node->key)
            return node;

        return nullptr;
        throw "Invalid key!";
    }

    void FixInsert(Node* node)
    {
        if (!node->parent) {
            node->color = 0;
            return;
        }

        if (!node->parent->color)
            return;

        if (!node->parent->parent) {
            node->parent->color = 0;
            return;
        }

        if (Node* uncle = Uncle(node)) {
            if (uncle->color) {
                node->parent->color = uncle->color = 0;
                node->parent->parent->color = 1;
                FixInsert(node->parent->parent);
                return;
            }
        }

        if (node->parent->parent->left == node->parent && node->parent->right == node) {
            RotateLeft(node->parent);
            FixInsert(node->left);
            return;
        }

        if (node->parent->parent->right == node->parent && node->parent->left == node) {
            RotateRight(node->parent);
            FixInsert(node->right);
            return;
        }

        node->parent->color = 0;
        node->parent->parent->color = 1;

        if (node->parent->parent->left == node->parent && node->parent->left == node) {
            RotateRight(node->parent->parent);
            return;
        }

        if (node->parent->parent->right == node->parent && node->parent->right == node) {
            RotateLeft(node->parent->parent);
            return;
        }

        throw "Insert fail!";
    }

    Node* Search(KeyT& key) {
        Node* current = root;
        while (current) {
            if (key == current->key)
                break;
            if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }

        return current;
    }

    void Delete(KeyT& key) {
        Node* node = Search(key);
        if (!node)
            return;

        if (node->left && node->right) {
            Node* replacement = node->right;
            while (replacement->left)
                replacement = replacement->left;

            node->key = std::move(replacement->key);
            node->value = std::move(replacement->value);

            node = replacement;
        }

        if (node->left && !node->right) {
            Node* temp = node;
            node->left->color = 0;
            node->left->parent = node->parent;
            if (node->parent && node->parent->left == node)
                node->parent->left = node->left;
            else if (node->parent)
                node->parent->right = node->left;
            else
                root = node->left;
            node = node->left;

            delete temp;
            return;
        }

        if (!node->left && node->right) {
            Node* temp = node;
            node->right->color = 0;
            node->right->parent = node->parent;
            if (node->parent && node->parent->left == node)
                node->parent->left = node->right;
            else if (node->parent)
                node->parent->right = node->right;
            else
                root = node->right;
            node = node->right;

            delete temp;
            return;
        }

        if (node == root) {
            delete root;
            root = nullptr;
            return;
        }

        if (node->color) {
            if (node == node->parent->left)
                node->parent->left = nullptr;
            else
                node->parent->right = nullptr;
            delete node;
            return;
        }

        Node* temp = node;
        FixDelete(node);
        if (temp->parent->left == temp)
            temp->parent->left = nullptr;
        else
            temp->parent->right = nullptr;
        delete temp;
        while (root->parent)
            root = root->parent;
        return;
    }

    void FixDelete(Node* node)
    {
        if (!node->parent)
            return;

        Node* sibling = Sibling(node);

        if (!node->parent->color && !sibling->color && !(sibling->left && sibling->left->color) && !(sibling->right && sibling->right->color)) {
            sibling->color = 1;
            FixDelete(node->parent);
            return;
        }

        if (sibling->color) {

            sibling->color = 0;
            node->parent->color = 1;

            if (node == node->parent->left)
                RotateLeft(node->parent);
            else
                RotateRight(node->parent);

            FixDelete(node);
            return;
        }

        if (node->parent->color && !sibling->color && !(sibling->left && sibling->left->color) && !(sibling->right && sibling->right->color)) {
            sibling->color = 1;
            node->parent->color = 0;
            return;
        }

        Node* close = CloseNephew(node);
        Node* distant = DistantNephew(node);

        if (!sibling->color && (close && close->color) && !(distant && distant->color)) {
            sibling->color = 1;
            close->color = 0;

            if (sibling->left == close)
                RotateRight(sibling);
            else
                RotateLeft(sibling);

            FixDelete(node);
            return;
        }

        if (!sibling->color && (distant && distant->color)) {
            sibling->color = node->parent->color;
            node->parent->color = 0;
            distant->color = 0;

            if (node == node->parent->left)
                RotateLeft(node->parent);
            else
                RotateRight(node->parent);
            return;
        }

        throw "Delete fail!";
    }

    bool Contains(KeyT key) {
        return Search(key) != nullptr;
    }

    void Clear()
    {
        Clear(root);
        root = nullptr;
    }

    void Clear(Node *node)
    {
        if (!node)
            return;
        Clear(node->left);
        Clear(node->right);
        delete node;
    }

    size_t Size()
    {
        return Size(root);
    }

    size_t Size(Node* node)
    {
        if (!node)
            return 0;
        return Size(node->left) + Size(node->right) + 1;
    }

    size_t Height()
    {
        Height(root);
    }

    size_t Height(Node* node)
    {
        if (!node)
            return 0;
        return std::max(Height(node->left), Height(node->right)) + 1;
    }

    void RotateLeft(Node* node)
    {
        Node *pivot = node->right;

        pivot->parent = node->parent;
        if (node->parent != nullptr) {
            if (node->parent->left == node)
                node->parent->left = pivot;
            else
                node->parent->right = pivot;
        }

        node->right = pivot->left;
        if (pivot->left != nullptr)
            pivot->left->parent = node;

        node->parent = pivot;
        pivot->left = node;
    }

    void RotateRight(Node* node)
    {
        Node *pivot = node->left;

        pivot->parent = node->parent;
        if (node->parent != nullptr) {
            if (node->parent->right == node)
                node->parent->right = pivot;
            else
                node->parent->left = pivot;
        }

        node->left = pivot->right;
        if (pivot->right != nullptr)
            pivot->right->parent = node;

        node->parent = pivot;
        pivot->right = node;
    }

    class Iterator {
        friend class RedBlackTree<KeyT, ValueT>;
    protected:
        Node* current;
        Iterator(Node *root) : current(root) {
            if (!current) return;
            while (current->left != nullptr)
                current = current->left;
        }

    public:
        Node *operator->()
        {
            return current;
        }

        Node &operator*()
        {
            return *current;
        }

        Iterator &operator++()
        {
            if (!current)
                return *this;

            if (current->right != nullptr) {
                current = current->right;
            while (current->left != nullptr)
                current = current->left;
            }

            else {
                while (current->parent != nullptr && current->parent->right == current) {
                    current = current->parent;
                }
                current = current->parent;
            }


            return *this;
        }

        bool operator==(const Iterator &other)
        {
            return current == other.current;
        }

        bool operator!=(const Iterator &other)
        {
            return !(*this == other);
        }
    };

    Iterator begin() { return Iterator(root); }
    Iterator end() { return Iterator(nullptr); }
};

// template <typename KeyT, typename ValueT>
// class Map : public RedBlackTree<KeyT, ValueT>
// {
//     using RedBlackTree = RedBlackTree<KeyT, ValueT>;
// public:
//     struct Node* Insert(KeyT key, ValueT value)
//     {
//         return RedBlackTree::Insert(key, value);
//     }
//     struct Node* Find(KeyT key)
//     {
//         return RedBlackTree::Search(key);
//     }
//     void Erase(KeyT key)
//     {
//         RedBlackTree::Delete(key);
//     }
//     bool Empty() {
//         return RedBlackTree::Size() == 0;
//     }

//     ValueT& operator[](const KeyT key) {
//         struct Node* t = RedBlackTree::Search(key);
//         if (t) {
//             return RedBlackTree::Search(key)->value;
//         }
//         return RedBlackTree::Insert(key, ValueT())->value;
//     }
// };

// template <typename KeyT>
// class Set : public RedBlackTree<KeyT, char>
// {
//     using RedBlackTree = RedBlackTree<KeyT, char>;
// public:
//     Node* Insert(KeyT key)
//     {
//         char c = '\0';
//         return RedBlackTree::Insert(key, c);
//     }
//     Node* Find(KeyT key)
//     {
//         return RedBlackTree::Search(key);
//     }
//     void Erase(KeyT key)
//     {
//         RedBlackTree::Delete(key);
//     }
//     bool Empty() {
//         return RedBlackTree::Size() == 0;
//     }
// };

#endif // REDBLACKTREE_H
