#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <deque>

/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
*/

//#define TREELEVELORDER3

#ifdef TREELEVELORDER3
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

    int level = 0;
    deque<TreeNode*> queue;
    queue.push_back(root);
    while (queue.size() != 0) {
        vector<int> order;
        int size = queue.size();
        for (size_t idx = 0; idx < size; idx++) {
            TreeNode* node = queue.front();
            queue.pop_front();

            order.push_back(node->val);
            if (node->left != nullptr) {
                queue.push_back(node->left);
            }
            if (node->right != nullptr) {
                queue.push_back(node->right);
            }
        }
        if (level == 1) {
            std::reverse(order.begin(), order.end());
        }
        orders.push_back(order);
        level = 1 - level;
    }
    return orders;
}

int main(int argc, char** argv)
{
    TreeNode root(1);
    TreeNode root1_1(2);
    TreeNode root1_2(3);
    root.left = &root1_1;
    root.right = &root1_2;

    TreeNode root2_1(4);
    TreeNode root2_2(5);
    root1_1.left = &root2_1;
    root1_2.right = &root2_2;

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
#endif // TREELEVELORDER3
