#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
2. 两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode head;
    ListNode* cur = &head;
    int add = 0;
    while (l1 != nullptr && l2 != nullptr) {
        int sum = l1->val + l2->val + add;
        int val = sum % 10;
        add = sum / 10;
        ListNode* node = new ListNode(val);
        cur->next = node;
        cur = node;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != nullptr) {
        int sum = l1->val + add;
        int val = sum % 10;
        add = sum / 10;
        ListNode* node = new ListNode(val);
        cur->next = node;
        cur = node;
        l1 = l1->next;
    }
    while (l2 != nullptr) {
        int sum = l2->val + add;
        int val = sum % 10;
        add = sum / 10;
        ListNode* node = new ListNode(val);
        cur->next = node;
        cur = node;
        l2 = l2->next;
    }
    if (add > 0) {
        ListNode* node = new ListNode(add);
        cur->next = node;
        cur = node;
    }
    cur->next = nullptr;
    return head.next;
}

#define ADD_TWO_NUMBERS
#ifdef ADD_TWO_NUMBERS

ListNode* CreateLinkedList(vector<int> vec)
{
    ListNode head;
    ListNode* last = &head;
    for (int val : vec) {
        ListNode* pnode = new ListNode(val);
        last->next = pnode;
        last = pnode;
    }
    return head.next;
}

void DeleteLinkedList(ListNode* head)
{
    ListNode* cur = head;
    ListNode* next = head;
    while (cur) {
        next = cur->next;
        delete cur;
        cur = next;
    }
}

void PrintLinkedList(ListNode* head)
{
    ListNode* cur = head;
    while (cur) {
        printf("%d\t", cur->val);
        cur = cur->next;
    }
}

int main(int argc, char* argv)
{
    ListNode* p0 = CreateLinkedList({ 2, 4, 3 });
    ListNode* p1 = CreateLinkedList({ 5, 6, 4 });
    ListNode* p2 = addTwoNumbers(p0, p1);

    PrintLinkedList(p2);

    DeleteLinkedList(p0);
    DeleteLinkedList(p1);
    DeleteLinkedList(p2);

    getchar();
    return 0;
}
#endif // ADD_TWO_NUMBERS
