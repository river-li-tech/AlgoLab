#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>

/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
要求不能创建任何新的节点，只能调整树中节点指针的指向。
*/

//#define TREETODOUBLYLIST

#ifdef TREETODOUBLYLIST
using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

Node *pre = nullptr;
Node* head = nullptr;

void dfs(Node* node)
{
    if (node == nullptr) return;

    dfs(node->left);
    if (pre == nullptr) {
        head = node;
    } else {
        pre->right = node;
        node->left = pre;
    }
    pre = node;
    dfs(node->right);
}

Node* treeToDoublyList(Node* root)
{
    if (root == nullptr) return nullptr;

    pre = nullptr;
    dfs(root);
    pre->right = head;
    head->left = pre;
    return head;
}

int main(int argc, char** argv)
{
    Node* n1 = new Node(1);
    Node* n3 = new Node(3);
    Node* n2 = new Node(2, n1, n3);
    Node* n5 = new Node(5);
    Node* n4 = new Node(4, n2, n5);

    Node* list = treeToDoublyList(n4);
    Node* node = list;
    for (size_t idx = 0; idx < 5; idx++) {
        printf("%d(left:%d|right:%d)\n", node->val, node->left->val, node->right->val);
        node = node->right;
    }
    printf("\n");

    getchar();
    return 0;
}
#endif // TREETODOUBLYLIST
