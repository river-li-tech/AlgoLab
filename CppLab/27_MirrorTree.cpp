#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
*/

//#define MIRRORTREE

#ifdef MIRRORTREE
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mirrorTree(TreeNode* root)
{
    if (!root) return nullptr;
    TreeNode* left = mirrorTree(root->left);
    TreeNode* right = mirrorTree(root->right);
    root->left = right;
    root->right = left;
    return root;
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
    PrintTreeLevelOrder(head1);

    TreeNode* head2 = mirrorTree(head1);
    PrintTreeLevelOrder(head2);

    getchar();
    return 0;
}
#endif // MIRRORTREE
