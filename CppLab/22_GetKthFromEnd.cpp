#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

/*
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，
本题从1开始计数，即链表的尾节点是倒数第1个节点。
*/

//#define GETKTHFROOMEND

#ifdef GETKTHFROOMEND
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getKthFromEnd(ListNode* head, int k)
{
    if (!head || k < 0) return head;
    if (k == 0) return nullptr;

    ListNode* pfront = head;
    ListNode* pend = head->next;
    int span = 1;
    while (pend != nullptr) {
        if (span < k) {
            pend = pend->next;
            span++;
        } else {
            pfront = pfront->next;            
            pend = pend->next;
        }
    }
    return (span < k)? nullptr : pfront;
}

ListNode* CreateNode(ListNode* parent, int val)
{
    ListNode* pnode = new ListNode(val);
    if (parent) {
        parent->next = pnode;
    }
    return pnode;
}

void PrintNode(ListNode* head)
{
    ListNode* pnode = head;
    while (pnode) {
        printf("%d\t", pnode->val);
        pnode = pnode->next;
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    ListNode* p0 = CreateNode(nullptr, 0);
    ListNode* p1 = CreateNode(p0, 1);
    ListNode* p2 = CreateNode(p1, 2);
    ListNode* p3 = CreateNode(p2, 3);
    ListNode* p4 = CreateNode(p3, 4);
    ListNode* p5 = CreateNode(p4, 5);
    PrintNode(p0);

    {
        ListNode* node = getKthFromEnd(p0, 1);
        if (node) {
            printf("Last %d, val:%d\n", 1, node->val);
        } else {
            printf("Last %d, val:miss\n", 1);
        }
    }

    {
        ListNode* node = getKthFromEnd(p0, 10);
        if (node) {
            printf("Last %d, val:%d\n", 10, node->val);
        } else {
            printf("Last %d, val:miss\n", 10);
        }
    }

    getchar();
    return 0;
}
#endif // GETKTHFROOMEND
