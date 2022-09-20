#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <unordered_map>
using namespace std;

/*
25. K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode fhead;
        ListNode* cur = head;
        ListNode* front = head;
        ListNode* end = head;
        ListNode* prev = &fhead;
        ListNode* last = nullptr;
        int cnt = 0;
        while (cur != nullptr) {
            front = cur;
            //步进K
            while (cnt < k && cur != nullptr) {
                last = cur;
                cur = cur->next;
                cnt++;
            }
            end = last;

            if (cnt == k) {
                //反转链表
                end->next = nullptr;
                reverse(front);
                //重置状态
                prev->next = end;
                front->next = cur;
                prev = front;
                front = end = cur;
            } else {
                //直接链接在尾部
                prev->next = front;
            }
            cnt = 0;
        }
        return fhead.next;
    }

    void reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    }
};
