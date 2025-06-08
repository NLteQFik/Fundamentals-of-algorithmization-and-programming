#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <QVector>
#include <QString>
#include <cmath>

class SearchTree
{
public:
    struct Node {
        QString info;
        int key;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(QString info, int key)
        {
            this->info = info;
            this->key = key;
            Node* left = nullptr;
            Node* right = nullptr;
        }
    };

    Node* root = nullptr;
public:
    SearchTree();

    SearchTree(QVector<QPair<int, QString>> info) {
        for (QPair<int, QString> el : info)
            Insert(el.first, el.second);
    }

    void BalanceTree();
    void BalanceTreeInNode(Node* &node);

    void Insert(int key, QString info);
    void InsertInNode(int key, QString info, Node* &node);

    QString Find(int key);
    QString FindInTree(int key, Node* node);

    void Remove(int key);
    void RemoveInTree(int key, Node* node, Node*& parent, int side);

    void PreOrder(Node* node, QVector<QString>& result);
    QVector<QString> preOrderTraversal();

    void InOrder(Node* node, QVector<QString>& result);
    QVector<QString> inOrderTraversal();

    void PostOrder(Node* node, QVector<QString>& result);
    QVector<QString> postOrderTraversal();

    Node* FindMin(Node* node);
    int GetHeight(Node* node);

    void RotateRight(Node* &node);
    void RotateLeft(Node* &node);

    void compress(Node* node, int count);
};

#endif // SEARCHTREE_H
