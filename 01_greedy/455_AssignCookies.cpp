/**
455. 分发饼干
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
 **/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& children, vector<int>& cookies) {
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());
        int child = 0, cookie = 0;
        while(child < children.size() && cookie < cookies.size()) {
            if (children[child] <= cookies[cookie]) {
                child++;
            }
            cookie++;
        }
        return child;
    }
};

int main()
{
    Solution sol;
    vector<int> children{1, 2, 3};
    vector<int> cookies{1, 1};
    int ret = sol.findContentChildren(children, cookies);
    cout << "children: " << ret << endl;
    return 0; 
}
