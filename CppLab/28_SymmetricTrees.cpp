#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

/*
请实现一个函数，用来判断一棵二叉树是不是对称的。
如果一棵二叉树和它的镜像一样，那么它是对称的。
*/

//#define SYMMETRICTREES

#ifdef SYMMETRICTREES
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetricTrees(TreeNode* rootA, TreeNode* rootB)
{
    if (rootA == nullptr && rootB == nullptr) return true;
    if (rootA == nullptr || rootB == nullptr) return false;

    if (rootA->val != rootB->val) return false;
    if (!isSymmetricTrees(rootA->left, rootB->right)) return false;
    if (!isSymmetricTrees(rootA->right, rootB->left)) return false;
    return true;
}

bool isSymmetric(TreeNode* root)
{
    return isSymmetricTrees(root, root);
}

TreeNode* CreateTreeLevelOrder(vector<vector<int>> vals)
{
    vector<vector<TreeNode*>> list;
    for (size_t row = 0; row < vals.size(); row++) {
        size_t cnt = (size_t)pow(2, row);
        if (vals[row].size() < cnt) {
            printf("CreateTreeLevelOrder error.\n");
            break;
        }
        vector<TreeNode*> rowlist;
        for (size_t col = 0; col < cnt; col++) {
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
        size_t size = queue.size();
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
        {2, 2},
        {3, 4, 4, 3}
    };
    TreeNode *head1 = CreateTreeLevelOrder(vals1);
    PrintTreeLevelOrder(head1);

    bool bsym = isSymmetric(head1);
    printf("isSymetric:%s\n", bsym ? "true" : "false");

    getchar();
    return 0;
}
#endif // SYMMETRICTREES
