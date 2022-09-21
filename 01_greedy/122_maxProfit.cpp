#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
*/
using namespace std;
int maxProfit(vector<int>& prices)
{
    int sum = 0;
    for (int idx = 1; idx < prices.size(); idx++) {
        sum += max(prices[idx] - prices[idx - 1], 0);
    }
    return sum;
}

//#define MAX_PROFIT
#ifdef MAX_PROFIT
int main(int argc, char** argv)
{
    vector<int> nums{ 7,1,5,3,6,4 };
    //vector<int> nums{ -1 };
    int sum = maxProfit(nums);
    printf("maxProfit:%d\n", sum);

    getchar();
    return 0;
}
#endif // MAX_PROFIT
