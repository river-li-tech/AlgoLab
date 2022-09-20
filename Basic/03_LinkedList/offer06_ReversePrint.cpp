#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
vector<int> ReversePrint(ListNode* head)
{
    //计算长度
    int count = 0;
    ListNode* node = head;
    while (node) {
        count++;
        node = node->next;
    }
    //正向遍历，反向存储
    vector<int> output(count);
    node = head;
    for (int idx = count - 1; idx >= 0; idx--) {
        output[idx] = node->val;
        node = node->next;
    }
    return output;
}

//#define REVERTPRINTLINK

#ifdef REVERTPRINTLINK
int main(int argc, char** argv)
{
    ListNode head(1);
    ListNode node1(2);
    ListNode node2(3);
    head.next = &node1;
    node1.next = &node2;

    vector<int> output = ReversePrint(&head);
    for_each(output.begin(), output.end(), [](int elem) {printf("%d\t", elem);});
    getchar();

    return 0;
}
#endif // REVERTPRINTLINK
