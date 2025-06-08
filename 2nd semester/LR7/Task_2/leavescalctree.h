#ifndef LEAVESCALCTREE_H
#define LEAVESCALCTREE_H

#include <searchtree.h>

class LeavesCalcTree : public SearchTree
{
public:
    LeavesCalcTree() : SearchTree() {}
    LeavesCalcTree(QVector<QPair<int, QString>> info) : SearchTree(info) {}

    int CalcLeaves() {
        return CalcLeavesInNode(root);
    }

    int CalcLeavesInNode(Node* node) {
        if (node == nullptr)
            return 1;
        return CalcLeavesInNode(node->left) + CalcLeavesInNode(node->right);
    }
};

#endif // LEAVESCALCTREE_H
