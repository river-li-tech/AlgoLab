#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <queue>

using namespace std;

/*
143. 重排链表
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode* head)
    {
        //获取中间位置，记得把前半段的末尾置为nullptr
        ListNode* pmid = getMiddle(head);
        ListNode* pend = pmid->next;
        pmid->next = nullptr;

        //反转链表
        pend = reverse(pend);

        //合并链表
        merge(head, pend);
    }

    //提取出后半段链表的头部位置, pslow
    ListNode* getMiddle(ListNode* head)
    {
        ListNode* pfast = head;
        ListNode* pslow = head;

        while (pfast->next != nullptr && pfast->next->next != nullptr) {
            pfast = pfast->next->next;
            pslow = pslow->next;
        }
        return pslow;
    }

    //反转链表
    ListNode* reverse(ListNode* head)
    {
        ListNode* ppre = nullptr;
        ListNode* pcur = head;
        ListNode* pnext = nullptr;
        while (pcur != nullptr) {
            pnext = pcur->next;
            pcur->next = ppre;
            ppre = pcur;
            pcur = pnext;
        }
        return ppre;
    }

    //合并链表
    void merge(ListNode* pfront, ListNode* pend)
    {
        ListNode* tpfront = nullptr;
        ListNode* tpend = nullptr;
        while (pfront != nullptr && pend != nullptr) {
            tpfront = pfront->next;
            tpend = pend->next;

            pfront->next = pend;
            pfront = tpfront;

            pend->next = pfront;
            pend = tpend;
        }
    }
};
