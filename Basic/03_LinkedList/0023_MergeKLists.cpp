#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <queue>

using namespace std;

/*
23. 合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。
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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode head;
        ListNode* cur = &head;
        priority_queue<ListNode*, vector<ListNode*>, decltype(&cmp)> que(cmp);
        for (auto list : lists) {
            if (list != nullptr) {
                que.push(list);
            }
        }
        while (!que.empty()) {
            ListNode* node = que.top();
            que.pop();
            cur->next = node;
            cur = node;
            if (node->next != nullptr) {
                que.push(node->next);
            }
        }
        return head.next;
    }

private:
    static bool cmp(ListNode* left, ListNode* right)
    {
        return left->val > right->val;
    }
};