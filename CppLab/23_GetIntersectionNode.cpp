#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

/*
给定两个单链表的头节点 headA 和 headB ，
请找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
*/

#define GETINTERSECTIONNODE

#ifdef GETINTERSECTIONNODE
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    if (!headA || !headB) return nullptr;
    ListNode* pa = headA;
    ListNode* pb = headB;

    bool bswitcha = false;
    bool bswitchb = false;
    while (pa && pb) {
        if (pa == pb) {
            return pa;
        }
        pa = pa->next;
        pb = pb->next;
        if (!pa && !bswitcha) {
            pa = headB;
            bswitcha = true;
        }
        if (!pb && !bswitchb) {
            pb = headA;
            bswitchb = true;
        }
    }
    return nullptr;
}
//改进：2指针同时为空表示都执行完了
ListNode* getIntersectionNode2(ListNode* headA, ListNode* headB)
{
    if (!headA || !headB) return nullptr;
    ListNode* pa = headA;
    ListNode* pb = headB;

    while (pa || pb) {
        if (pa == pb) {
            return pa;
        }
        pa = (pa == nullptr) ? headB : pa->next;
        pb = (pb == nullptr) ? headA : pb->next;
    }
    return nullptr;
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
    ListNode* p6 = CreateNode(p5, 6);
    PrintNode(p0);

    ListNode* t0 = CreateNode(nullptr, 10);
    ListNode* t1 = CreateNode(t0, 11);
    ListNode* t2 = CreateNode(t1, 12);
    t2->next = p4;
    PrintNode(t0);

    ListNode* pnode = getIntersectionNode2(p0, t0);
    if (pnode) {
        printf("getIntersectionNode:%d\n", pnode->val);
    }

    getchar();
    return 0;
}
#endif // GETINTERSECTIONNODE
