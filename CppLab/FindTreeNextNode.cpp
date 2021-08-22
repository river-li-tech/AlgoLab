#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

//#define FINDTREENEXTNODE

#ifdef FINDTREENEXTNODE
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(TreeNode *p, int x) : parent(p), val(x), left(nullptr), right(nullptr) {}
};

TreeNode* FindNextTreeNode(TreeNode* root)
{
    if (root == nullptr) return nullptr;

    TreeNode* pnext = nullptr;
    //有右子节点，遍历找到最左子节点
    if (root->right != nullptr) {
        TreeNode* node = root->right;
        while (node->left != nullptr) {
            node = node->left;
        }
        pnext = node;
    }
    //只有父节点，往上找到非右子节点
    else if (root->parent != nullptr) {
        TreeNode* curNode = root;
        TreeNode* parent = curNode->parent;
        while (parent != nullptr && curNode == parent->right) {
            curNode = parent;
            parent = curNode->parent;
        }
        pnext = parent;
    }
    return pnext;
}

void SetNode(TreeNode* parent, TreeNode* left, TreeNode* right)
{
    parent->left = left;
    parent->right = right;
    if (left != nullptr) {
        left->parent = parent;
    }
    if (right != nullptr) {
        right->parent = parent;
    }
}

void PrintNextNode(TreeNode* node)
{
    TreeNode* next = FindNextTreeNode(node);
    if (next != nullptr) {
        printf("%d->%d\n", node->val, next->val);
    } else {
        printf("%d->null\n", node->val);
    }
}

int main(int argc, char** argv)
{
    TreeNode* n1 = new TreeNode(nullptr, 1);
    TreeNode* n2 = new TreeNode(nullptr, 2);
    TreeNode* n3 = new TreeNode(nullptr, 3);
    TreeNode* n4 = new TreeNode(nullptr, 4);
    TreeNode* n5 = new TreeNode(nullptr, 5);
    TreeNode* n6 = new TreeNode(nullptr, 6);
    TreeNode* n7 = new TreeNode(nullptr, 7);
    TreeNode* n8 = new TreeNode(nullptr, 8);
    TreeNode* n9 = new TreeNode(nullptr, 9);
    TreeNode* n10 = new TreeNode(nullptr, 10);

    SetNode(n1, n2, n3);
    SetNode(n2, n4, n5);
    SetNode(n3, n6, n7);
    SetNode(n5, n8, n9);
    SetNode(n6, nullptr, n10);

    PrintNextNode(n1);
    PrintNextNode(n2);
    PrintNextNode(n3);
    PrintNextNode(n4);
    PrintNextNode(n5);
    PrintNextNode(n6);
    PrintNextNode(n7);
    PrintNextNode(n8);
    PrintNextNode(n9);
    PrintNextNode(n10);

    getchar();

    return 0;
}
#endif // FINDTREENEXTNODE
