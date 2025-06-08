#include "searchtree.h"

SearchTree::SearchTree() {}

void SearchTree::BalanceTree()
{
    BalanceTreeInNode(root);
}

void SearchTree::BalanceTreeInNode(Node *&node)
{
    Node* grand = new Node("", 0);
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

void SearchTree::Insert(int key, QString info)
{
    InsertInNode(key, info, root);
}

void SearchTree::InsertInNode(int key, QString info, Node* &node)
{
    if (node == nullptr)
        node = new Node(info, key);
    else if (key <= node->key)
        InsertInNode(key, info, node->left);
    else
        InsertInNode(key, info, node->right);
}

QString SearchTree::Find(int key)
{
    return FindInTree(key, root);
}

QString SearchTree::FindInTree(int key, Node *node)
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

void SearchTree::Remove(int key)
{
    Node* a = nullptr;
    RemoveInTree(key, root, a, 1);
}

void SearchTree::RemoveInTree(int key, Node *node, Node *&parent, int side)
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

QVector<QString> SearchTree::preOrderTraversal() {
    QVector<QString> result;
    PreOrder(root, result);
    return result;
}

QVector<QString> SearchTree::inOrderTraversal() {
    QVector<QString> result;
    InOrder(root, result);
    return result;
}

QVector<QString> SearchTree::postOrderTraversal() {
    QVector<QString> result;
    PostOrder(root, result);
    return result;
}

void SearchTree::PreOrder(Node *node, QVector<QString> &result)
{
    if (node == nullptr) return;
    result.push_back(QString::number(node->key) + " " + node->info);
    PreOrder(node->left, result);
    PreOrder(node->right, result);
}

void SearchTree::InOrder(Node *node, QVector<QString> &result)
{
    if (node == nullptr) return;
    InOrder(node->left, result);
    result.push_back(QString::number(node->key) + " " + node->info);
    InOrder(node->right, result);
}

void SearchTree::PostOrder(Node *node, QVector<QString> &result)
{
    if (node == nullptr) return;
    PostOrder(node->left, result);
    PostOrder(node->right, result);
    result.push_back(QString::number(node->key) + " " + node->info);
}

SearchTree::Node *SearchTree::FindMin(Node *node)
{
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

int SearchTree::GetHeight(Node *node)
{
    if (node == nullptr)
        return 0;
    return 1 + std::max(GetHeight(node->left), GetHeight(node->right));
}

void SearchTree::RotateRight(Node *&node)
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

void SearchTree::RotateLeft(Node *&node)
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

void SearchTree::compress(Node *grand, int count)
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

