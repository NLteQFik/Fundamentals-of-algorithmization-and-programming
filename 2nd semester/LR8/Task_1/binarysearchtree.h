#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <QVector>
#include <cmath>

template <typename KeyT, typename ValueT>
class BinarySearchTree
{
public:
    struct Node {
        ValueT info;
        KeyT key;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(ValueT info, KeyT key)
        {
            this->info = info;
            this->key = key;
            Node* left = nullptr;
            Node* right = nullptr;
        }
    };

    Node* root = nullptr;
public:
    BinarySearchTree();

    BinarySearchTree(QVector<QPair<KeyT, ValueT>> info) {
        for (QPair<KeyT, ValueT> el : info)
            Insert(el.first, el.second);
    }

    void BalanceTree()
    {
        BalanceTreeInNode(root);
    }
    void BalanceTreeInNode(Node* &node)
    {
        Node* grand = new Node(ValueT(), KeyT());
        Node* base = grand;
        grand->right = node;

        int count = 0;
        Node* temp = grand->right;

        while (temp) {
            if (temp->left) {
                Node* oldTemp = temp;
                temp = temp->left;
                oldTemp->left = temp->right;
                temp->right = oldTemp;
                grand->right = temp;
            }
            else {
                count++;
                grand = temp;
                temp = temp->right;
            }
        }

        int h = log2(count + 1);
        int m = (int)pow(2, h) - 1;
        grand = base;

        compress(grand, count - m);
        for (m = m / 2; m > 0; m /= 2) {
            compress(grand, m);
        }

        node = base->right;
    }

    void Insert(KeyT key, ValueT info)
    {
        InsertInNode(key, info, root);
    }
    void InsertInNode(KeyT key, ValueT info, Node* &node)
    {
        if (node == nullptr)
            node = new Node(info, key);
        else if (key <= node->key)
            InsertInNode(key, info, node->left);
        else
            InsertInNode(key, info, node->right);
    }

    QString Find(KeyT key)
    {
        return FindInTree(key, root);
    }
    QString FindInTree(KeyT key, Node* node)
    {
        if (node == nullptr)
            return "";
        if (key == node->key)
            return node->info;
        if (key < node->key)
            return FindInTree(key, node->left);
        else
            return FindInTree(key, node->right);
    }

    void Remove(KeyT key)
    {
        Node* a = nullptr;
        RemoveInTree(key, root, a, 1);
    }
    void RemoveInTree(KeyT key, Node* node, Node*& parent, int side)
    {
        if (node == nullptr)
            return;
        if (key < node->key) {
            RemoveInTree(key, node->left, node, -1);
        } else if (key > node->key) {
            RemoveInTree(key, node->right, node, 1);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                if (parent == nullptr) {
                    delete node;
                    root = nullptr;
                } else {
                    if (side == -1)
                        parent->left = nullptr;
                    else if (side == 1)
                        parent->right = nullptr;
                    delete node;
                }
            }

            else if (node->left == nullptr) {
                if (parent == nullptr) {
                    root = node->right;
                } else {
                    if (side == -1)
                        parent->left = node->right;
                    else if (side == 1)
                        parent->right = node->right;
                }
                delete node;
            }

            else if (node->right == nullptr) {
                if (parent == nullptr) {
                    root = node->left;
                } else {
                    if (side == -1)
                        parent->left = node->left;
                    else if (side == 1)
                        parent->right = node->left;
                }
                delete node;
            }

            else {
                Node* successor = FindMin(node->right);
                node->key = successor->key;
                node->info = successor->info;
                RemoveInTree(successor->key, node->right, node, 1);
            }
        }
    }

    void PreOrder(Node* node, QVector<KeyT>& result)
    {
        if (node == nullptr) return;
        result.push_back(node->key);
        PreOrder(node->left, result);
        PreOrder(node->right, result);
    }
    QVector<KeyT> preOrderTraversal() {
        QVector<KeyT> result;
        PreOrder(root, result);
        return result;
    }

    void InOrder(Node* node, QVector<KeyT>& result)
    {
        if (node == nullptr) return;
        InOrder(node->left, result);
        result.push_back(node->key);
        InOrder(node->right, result);
    }
    QVector<KeyT> inOrderTraversal() {
        QVector<KeyT> result;
        InOrder(root, result);
        return result;
    }

    void PostOrder(Node* node, QVector<KeyT>& result)
    {
        if (node == nullptr) return;
        PostOrder(node->left, result);
        PostOrder(node->right, result);
        result.push_back(node->key);
    }
    QVector<KeyT> postOrderTraversal() {
        QVector<KeyT> result;
        PostOrder(root, result);
        return result;
    }

    Node* FindMin(Node* node)
    {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    int GetHeight(Node* node)
    {
        if (node == nullptr)
            return 0;
        return 1 + std::max(GetHeight(node->left), GetHeight(node->right));
    }

    void RotateRight(Node* &node)
    {
        if (node == nullptr)
            return;
        if (node->left == nullptr)
            return;
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node = temp;
    }
    void RotateLeft(Node* &node)
    {
        if (node == nullptr)
            return;
        if (node->right == nullptr)
            return;
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node = temp;
    }

    void compress(Node* grand, int count)
    {
        Node* temp = grand->right;
        if (!temp)
            return;
        if (!temp->right)
            return;
        for (int i = 0; i < count; i++) {
            Node* oldTemp = temp;
            temp = temp->right;
            grand->right = temp;
            oldTemp->right = temp->left;
            temp->left = oldTemp;
            grand = temp;
            temp = temp->right;
        }
    }

    void ClearTree(Node* node) {
        if (node != nullptr) {
            ClearTree(node->left);
            ClearTree(node->right);
            delete node;
        }
    }

    Node* FindLCA(KeyT n1, KeyT n2) {
        return FindLCA(root, n1, n2);
    }

    Node* FindLCA(Node* node, KeyT n1, KeyT n2) {
        if (node == nullptr) return nullptr;

        if (node->key > n1 && node->key > n2)
            return FindLCA(node->left, n1, n2);

        if (node->key < n1 && node->key < n2)
            return FindLCA(node->right, n1, n2);

        return node;
    }

    void InsertSubtree(Node* subtree) {
        if (!subtree)
            return;
        Insert(subtree->key, subtree->value);
        InsertSubtree(subtree->left);
        InsertSubtree(subtree->right);
    }

    void RemoveSubtree(KeyT key)
    {
        Node* node = Find(key);
        if (node)
            ClearTree(node);
    }

    void InsertBranch(Node* branch) {
        InsertSubtree(branch);
    }

    void RemoveBranch(KeyT key) {
        RemoveSubtree(key);
    }


};

#endif // BINARYSEARCHTREE_H
