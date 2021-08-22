#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

//#define BUILDTREE

#ifdef BUILDTREE
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* BuildTreeRecursively(vector<int>& preorder, int prestart, int prelength,
    vector<int>& inorder, int instart, int inlength)
{
    if (prelength == 0 || inlength != prelength) {
        return nullptr;
    }

    //前序队列第一个作为中心节点
    int val = preorder[prestart];
    TreeNode* node = new TreeNode(val);
    
    //查找其再中序遍历中的位置
    int valIdx = -1;
    for (int idx = 0; idx < inlength; idx++) {
        if (inorder[idx + instart] == val) {
            valIdx = idx + instart;
            break;
        }
    }
    if (valIdx < 0) {
        return nullptr;
    }

    int leftTreeLength = valIdx - instart;
    int rightTreeLengh = instart + inlength - valIdx - 1;
    //构造左右子树
    if (leftTreeLength > 0) {
        node->left = BuildTreeRecursively(preorder, prestart + 1, leftTreeLength,
            inorder, instart, leftTreeLength);
    }
    if (rightTreeLengh > 0) {
        node->right = BuildTreeRecursively(preorder, prestart + leftTreeLength + 1, rightTreeLengh,
            inorder, valIdx + 1, rightTreeLengh);
    }

    return node;
}

TreeNode* BuildTree(vector<int>& preorder, vector<int>& inorder)
{
    return BuildTreeRecursively(preorder, 0, preorder.size(),
        inorder, 0, inorder.size());
}

void PrintTreeLevelOrder(TreeNode* root)
{
    queue<TreeNode*> queue;
    queue.push(root);
    while (queue.size() > 0) {
        int curCnt = queue.size();
        for (int idx = 0; idx < curCnt; idx++) {
            TreeNode* node = queue.front();
            queue.pop();
            if (node != nullptr) {
                printf("%d\t", node->val);
            }
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
    }
}

int main(int argc, char** argv)
{
    vector<int> preorder{ 3,9,20,15,7 };
    vector<int> inorder{ 9,3,15,20,7 };

    TreeNode *tree = BuildTree(preorder, inorder);
    PrintTreeLevelOrder(tree);
    getchar();

    return 0;
}
#endif // BUILDTREE
