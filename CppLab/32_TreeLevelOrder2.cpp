#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>

/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
*/

//#define TREELEVELORDER2

#ifdef TREELEVELORDER2
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> orders;
    if (root == nullptr) {
        return orders;
    }

    queue<TreeNode*> queue;
    queue.push(root);
    while (queue.size() != 0) {
        vector<int> order;
        int size = queue.size();
        for (size_t idx = 0; idx < size; idx++) {
            TreeNode* node = queue.front();
            queue.pop();

            order.push_back(node->val);
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
        orders.push_back(order);
    }
    return orders;
}

int main(int argc, char** argv)
{
    TreeNode root(3);
    TreeNode root1_1(9);
    TreeNode root1_2(20);
    root.left = &root1_1;
    root.right = &root1_2;

    TreeNode root2_1(15);
    TreeNode root2_2(7);
    root1_2.left = &root2_1;
    root1_2.right = &root2_2;

    vector<int> inorder{ 9,3,15,20,7 };

    vector<vector<int>> orders = levelOrder(&root);
    for (size_t oidx = 0; oidx < orders.size(); oidx++) {
        vector<int>& order = orders[oidx];
        for (size_t iidx = 0; iidx < order.size(); iidx++) {
            printf("%d\t", order[iidx]);
        }
        printf("\n");
    }
    printf("\n");

    getchar();

    return 0;
}
#endif // TREELEVELORDER2
