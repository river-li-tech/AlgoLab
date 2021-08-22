#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

//#define REVERTPRINTLINK

#ifdef REVERTPRINTLINK
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
vector<int> RevertPrintLink(ListNode* head)
{
    int count = 0;
    ListNode* node = head;
    while (node) {
        count++;
        node = node->next;
    }

    vector<int> output(count);
    node = head;
    for (int idx = count - 1; idx >= 0; idx--) {
        output[idx] = node->val;
        node = node->next;
    }

    return output;
}

int main(int argc, char** argv)
{
    ListNode head(1);
    ListNode node1(2);
    ListNode node2(3);
    head.next = &node1;
    node1.next = &node2;

    vector<int> output = RevertPrintLink(&head);
    for_each(output.begin(), output.end(), [](int elem) {printf("%d\t", elem);});
    getchar();

    return 0;
}
#endif // REVERTPRINTLINK
