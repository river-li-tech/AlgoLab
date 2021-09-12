#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>

/*
请实现两个函数，分别用来序列化和反序列化二叉树。
*/

//#define SERIALIZETREE

#ifdef SERIALIZETREE
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *_left, TreeNode *_right) : val(x), left(_left), right(_right) {}
};

list<string> split(string &str, char delim)
{
    list<string> ret;
    stringstream ss(str);
    string item;
    while (getline(ss, item, delim)) {
        ret.push_back(item);
    }
    return ret;
}

void serializeInternal(TreeNode* node, string &str)
{
    if (node == nullptr) {
        str += "null,";
    } else {
        str += to_string(node->val) + ",";
        serializeInternal(node->left, str);
        serializeInternal(node->right, str);
    }
}

string serialize(TreeNode* root)
{
    if (root == nullptr) return "[]";

    string str = "[";
    serializeInternal(root, str);
    str += "]";
    return str;
}

TreeNode* deserializeInternal(list<string> &strs)
{
    if (strs.size() == 0) return nullptr;

    string str = strs.front();
    if (str.compare("null") == 0) {
        strs.erase(strs.begin());
        return nullptr;
    }
    TreeNode* node = new TreeNode(atoi(str.c_str()));
    strs.erase(strs.begin());
    node->left = deserializeInternal(strs);
    node->right = deserializeInternal(strs);
    return node;
}

TreeNode* deserialize(string data)
{
    if (data.compare("[]") == 0) return nullptr;
    string str = data.substr(1, data.size() - 2);
    list<string> strs = split(str, ',');
    return deserializeInternal(strs);
}

int main(int argc, char** argv)
{
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(2, n1, n3);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(4, n2, n5);

    string str = serialize(n4);
    printf("serialize:%s\n", str.c_str());

    TreeNode* nodeNew = deserialize(str);
    string strNew = serialize(nodeNew);
    printf("serializeNew:%s\n", strNew.c_str());

    getchar();
    return 0;
}
#endif // SERIALIZETREE
