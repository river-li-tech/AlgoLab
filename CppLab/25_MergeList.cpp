#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
*/

//#define MERGELIST

#ifdef MERGELIST
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode* p1 = l1;
    ListNode* p2 = l2;
    //先取得头节点
    ListNode* head = nullptr;
    ListNode* pcur = nullptr;
    if (p1->val < p2->val) {
        pcur = p1;
        p1 = p1->next;
    } else {
        pcur = p2;
        p2 = p2->next;
    }
    head = pcur;
    //双指针遍历
    while (p1 && p2) {
        if (p1->val < p2->val) {
            pcur->next = p1;
            p1 = p1->next;
        } else {
            pcur->next = p2;
            p2 = p2->next;
        }
        pcur = pcur->next;
    }
    //剩余链表节点
    if (p1) {
        pcur->next = p1;
    } else {
        pcur->next = p2;
    }

    return head;
}

ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode* pnode = nullptr;
    if (l1->val < l2->val) {
        pnode = l1;
        pnode->next = mergeTwoLists2(l1->next, l2);
    } else {
        pnode = l2;
        pnode->next = mergeTwoLists2(l1, l2->next);
    }
    return pnode;
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
    ListNode* p0 = CreateNode(nullptr, 1);
    ListNode* p1 = CreateNode(p0, 4);
    ListNode* p2 = CreateNode(p1, 5);
    ListNode* p3 = CreateNode(p2, 13);
    ListNode* p4 = CreateNode(p3, 18);
    ListNode* p5 = CreateNode(p4, 55);
    PrintNode(p0);

    ListNode* t0 = CreateNode(nullptr, 3);
    ListNode* t1 = CreateNode(t0, 11);
    ListNode* t2 = CreateNode(t1, 13);
    ListNode* t3 = CreateNode(t2, 25);
    PrintNode(t0);

    //ListNode* node = mergeTwoLists(p0, t0);
    ListNode* node = mergeTwoLists2(p0, t0);
    PrintNode(node);

    getchar();
    return 0;
}
#endif // MERGELIST
