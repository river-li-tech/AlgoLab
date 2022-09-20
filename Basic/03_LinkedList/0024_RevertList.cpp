#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

/*
206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseList(ListNode* head)
{
    if (!head) return head;

    ListNode* plast = head;
    ListNode* pcur = plast->next;
    while (pcur) {
        ListNode* pnext = pcur->next;//保存下下节点
        pcur->next = plast;//反向
        //更新迭代器
        plast = pcur;
        pcur = pnext;
    }
    head->next = nullptr;

    return plast;
}

//#define REVERTLIST
#ifdef REVERTLIST
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
        ListNode* node = reverseList(p0);
        PrintNode(node);
    }

    getchar();
    return 0;
}
#endif // REVERTLIST
