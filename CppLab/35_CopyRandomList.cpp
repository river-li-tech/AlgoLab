#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>

/*
请实现 copyRandomList 函数，复制一个复杂链表。
在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
还有一个 random 指针指向链表中的任意节点或者 null。
*/

#define COPYRANDOMLIST

#ifdef COPYRANDOMLIST
using namespace std;
class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head)
{
    if (head == nullptr) return nullptr;
    //复制NodeNew添加到原节点的后边
    for (Node* pnode = head; pnode != nullptr; pnode = pnode->next->next) {
        Node* pnodenew = new Node(pnode->val);
        pnodenew->next = pnode->next;
        pnode->next = pnodenew;
    }
    //关联新节点的random指针
    for (Node* pnode = head; pnode != nullptr; pnode = pnode->next->next) {
        Node* pnodenew = pnode->next;
        pnodenew->random = (pnode->random != nullptr)? pnode->random->next:nullptr;
    }
    //分离出新链表
    Node* headnew = head->next;
    for (Node* pnode = head; pnode != nullptr; pnode = pnode->next) {
        Node* pnodenew = pnode->next;
        pnode->next = pnode->next->next;
        pnodenew->next = (pnodenew->next != nullptr) ? pnode->next->next : nullptr;
    }
    return headnew;
}

Node* CreateNode(Node* parent, int val)
{
    Node* pnode = new Node(val);
    if (parent) {
        parent->next = pnode;
    }
    return pnode;
}

void PrintNode(Node* head)
{
    Node* pnode = head;
    while (pnode) {
        printf("%d(%d)\t", pnode->val, (pnode->random)?pnode->random->val:-1);
        pnode = pnode->next;
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    Node* p0 = CreateNode(nullptr, 0);
    Node* p1 = CreateNode(p0, 1);
    Node* p2 = CreateNode(p1, 2);
    Node* p3 = CreateNode(p2, 3);
    Node* p4 = CreateNode(p3, 4);
    p2->random = p4;
    p3->random = p0;
    PrintNode(p0);

    Node* clone = copyRandomList(p0);
    PrintNode(clone);

    getchar();
    return 0;
}
#endif // COPYRANDOMLIST
