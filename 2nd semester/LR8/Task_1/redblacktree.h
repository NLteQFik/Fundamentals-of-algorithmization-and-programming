#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <utility>
#include <algorithm>

template <typename KeyT, typename ValueT>
class RedBlackTree
{
protected:
    struct Node {
        Node* parent = nullptr;
        Node* left = nullptr;
        Node* right = nullptr;
        bool color = 0; // 0 for black and 1 for red
        KeyT key;
        ValueT value;

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
    }

    Node* DistantNephew(Node* node)
    {
        if (Node* s = Sibling(node)) {
            if (node == node->parent->left)
                return s->right;
            else
                return s->left;
        }
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
                return node->left;
            }
        }

        if (key > node->key) {
            if (node->right)
                Insert(key, value, node->right);
            else {
                node->right = new Node(node, nullptr, nullptr, 1, key, value);
                FixInsert(node->right);
                return node->right;
            }
        }

        if (key == node->key)
            return node;

        throw "Invalid key!";
        return nullptr;
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
                node->parent->color = uncle->color = 1;
                node->parent->parent = 0;
                FixInsert(node->parent->parent);
                return;
            }
            throw "Insert fail!";
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

        node->parent = 0;
        node->parent->parent = 1;

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
            node = node->left;
            delete temp;
            return;
        }

        if (!node->left && node->right) {
            Node* temp = node;
            node->right->color = 0;
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
            if (node->parent->left == node)
                node->parent->left = nullptr;
            else
                node->parent->right = nullptr;
            delete node;
            return;
        }

        Node* temp = node;
        FixDelete(node);
        delete temp;
        return;
    }

    void FixDelete(Node* node)
    {
        if (node == root)
            return;

        Node* sibling = Sibling(node);

        if (!node->parent->color && !sibling->color && sibling->color && !(sibling->left && sibling->left->color) && !(sibling->right && sibling->right->color)) {
            sibling->color = 1;
            FixDelete(node->parent);
            return;
        }

        if (sibling->color) {

            sibling->color = 0;
            node->parent = 1;

            if (node == node->parent->left)
                RotateLeft(node->parent);
            else
                RotateRight(node->parent);

            FixDelete(node);
            return;
        }

        if (node->parent->color && !sibling->color && !(sibling->left && sibling->left->color) && !(sibling->right && sibling->right->color)) {
            sibling->color = 1;
            node->parent = 0;
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

            if (node->parent->left == node)
                RotateLeft(node->parent);
            else
                RotateRight(node->parent);

            return;
        }

        throw "Delete fail!";
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

    void Size()
    {
        Size(root);
    }

    void Size(Node* node)
    {
        if (!node)
            return 0;
        return Size(node->left) + Size(node->right) + 1;
    }

    void Height()
    {
        Height(root);
    }

    void Height(Node* node)
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
};

#endif // REDBLACKTREE_H
