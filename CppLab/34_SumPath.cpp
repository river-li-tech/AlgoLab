#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>

/*
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
*/

//#define SUMPATH

#ifdef SUMPATH
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> ret;
vector<int> path;

void dfs(TreeNode* root, int target)
{
    if (root == nullptr) return;

    path.push_back(root->val);
    target -= root->val;
    if (root->left == nullptr && root->right == nullptr && target == 0) {
        ret.push_back(path);
    }
    dfs(root->left, target);
    dfs(root->right, target);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int target)
{
    dfs(root, target);
    return ret;
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
    vector<vector<int>> vals = {
        {5},
        {4, 8},
        {11, -1, 13, 4},
        {7, 2, -1, -1, -1, -1, 5, 1}
    };
    TreeNode* root = CreateTreeLevelOrder(vals);
    PrintTreeLevelOrder(root);
    printf("\n");

    printf("sumPath:\n");
    vector<vector<int>> ret = pathSum(root, 22);
    for (auto vec : ret) {
        for (auto val : vec) {
            printf("%d\t", val);
        }
        printf("\n");
    }

    getchar();

    return 0;
}
#endif // SUMPATH
