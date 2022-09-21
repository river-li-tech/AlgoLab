/*
122. 买卖股票的最佳时机 II
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int sum = 0;
        for (int idx = 1; idx < prices.size(); idx++) {
            sum += max(prices[idx] - prices[idx - 1], 0);
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> prices{7,1,5,3,6,4};
    int ret = sol.maxProfit(prices);
    cout << "maxProfit:" << ret << endl;
}
