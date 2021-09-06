#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。
*/

#define SUBTREE

#ifdef SUBTREE
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* A, TreeNode* B)
{
    if (B == nullptr) return true;
    if (A == nullptr) return false;
    if (A->val != B->val) return false;
    return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
}

bool isSubStructure(TreeNode* A, TreeNode* B)
{
    if (A == nullptr || B == nullptr) return false;
    if (isSameTree(A, B)) return true;
    return isSubStructure(A->left, B) || isSubStructure(A->right, B);
}

TreeNode* CreateTreeLevelOrder(vector<vector<int>> vals)
{
    vector<vector<TreeNode*>> list;
    for (int row = 0; row < vals.size(); row++) {
        int cnt = pow(2, row);
        if (vals[row].size() < cnt) {
            printf("CreateTreeLevelOrder error.\n");
            break;
        }
        vector<TreeNode*> rowlist;
        for (int col = 0; col < cnt; col++) {
            TreeNode* pnode = nullptr;
            int val = vals[row][col];
            if (val >= 0) {
                pnode = new TreeNode(val);
                int parentIdx = col / 2;
                if (row >= 1) {
                    TreeNode* parent = list[row - 1][parentIdx];
                    if (parent) {
                        if ((col & 0x01) == 0) {
                            parent->left = pnode;
                        } else {
                            parent->right = pnode;
                        }
                    }
                }
            }
            rowlist.push_back(pnode);
        }
        list.push_back(rowlist);
    }
    if (list.size() > 0 && list[0].size() > 0) return list[0][0];
    else return nullptr;
}

void PrintTreeLevelOrder(TreeNode* root)
{
    queue<TreeNode*> queue;
    queue.push(root);
    while (queue.size() != 0) {
        int size = queue.size();
        for (size_t idx = 0; idx < size; idx++) {
            TreeNode* node = queue.front();
            queue.pop();

            printf("%d\t", node->val);
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
        printf("\n");
    }
}

int main(int argc, char** argv)
{
    vector<vector<int>> vals1 = {
        {1},
        {2, 3},
        {-1, -1, 4, 5}
    };
    TreeNode *head1 = CreateTreeLevelOrder(vals1);

    vector<vector<int>> vals2 = {
           {1},
           {2, 3},
           {-1, -1, 4, 5},
           {-1, -1, -1, -1, -1, -1, -1, 1}
    };
    TreeNode* head2 = CreateTreeLevelOrder(vals2);
    PrintTreeLevelOrder(head1);

    bool isSame = isSameTree(head1, head2);
    printf("isSameTree:%s\n", isSame ? "true" : "false");

    getchar();
    return 0;
}
#endif // SUBTREE
