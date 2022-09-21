/*
142. 环形链表 II
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        return GetEntryNode(head);
    }

    //获取环中的节点(也可用于判断是否有环)
    ListNode* GetLoopNode(ListNode* head)
    {
        if (!head) return nullptr;
        ListNode *p1, *p2;
        p1 = head->next;
        if (!p1) {
            return nullptr;
        }
        p2 = p1->next;
        while (p1 && p2) {
            if (p1 == p2) {
                return p1;
            }
            p1 = p1->next;//p1每次步进1
            p2 = p2->next;//p2每次步进2
            if (p2) {
                p2 = p2->next;
            }
        }
        return nullptr;
    }

    //环中节点再次回到原位置，表示绕环一圈
    int GetLoopLength(ListNode *node)
    {
        if (!node) return 0;

        int cnt = 1;
        ListNode* pcur = node->next;
        while (pcur) {
            if (pcur == node) break;//回到原位置
            pcur = pcur->next;
            cnt++;
        }
        return cnt;
    }

    //获取环入口：p1先走n步
    ListNode* GetEntryNode(ListNode* head)
    {
        if (!head) return nullptr;
        //获得环中节点
        ListNode* pnode = GetLoopNode(head);
        if (!pnode) {
            return nullptr;
        }
        //获得环长度
        int loopCnt = GetLoopLength(pnode);
        if (loopCnt <= 0) {
            return nullptr;
        }
        //p1先走环长度
        ListNode* p1, * p2;
        p1 = p2 = head;
        while (loopCnt > 0) {
            p1 = p1->next;
            loopCnt--;
        }
        //同时步进，重合点即为入口节点
        while (p1 && p2) {
            if (p1 == p2) {
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};

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
    p6->next = p3;
    //PrintNode(p0);

    Solution sol;
    ListNode* node = sol.GetLoopNode(p0);
    if (node) {
        printf("GetLoopNode:%d\n", node->val);
        printf("GetLoopLength:%d\n", sol.GetLoopLength(node));
    }
    ListNode* entryNode = sol.GetEntryNode(p0);
    if (entryNode) {
        printf("GetEntryNode:%d\n", entryNode->val);
    }

    return 0;
}

