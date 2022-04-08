#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
零钱兑换
*/

using namespace std;
int change(vector<int>& coins, int target)
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int itemIdx = 0; itemIdx < coins.size(); itemIdx++) {//遍历物品
        for (int bagIdx = 0; bagIdx <= target; bagIdx++) {//遍历背包
            if (bagIdx >= coins[itemIdx])
                dp[bagIdx] += dp[bagIdx - coins[itemIdx]];
        }
        for (int idx = 0; idx <= target; idx++) {
            printf("%d\t", dp[idx]);
        }
        printf("\n");
    }
    return dp[target];
}

int change2(vector<int>& coins, int target)
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int bagIdx = 0; bagIdx <= target; bagIdx++) {//遍历背包
        for (int itemIdx = 0; itemIdx < coins.size(); itemIdx++) {//遍历物品
            if (bagIdx >= coins[itemIdx])
                dp[bagIdx] += dp[bagIdx - coins[itemIdx]];
        }
        for (int idx = 0; idx <= target; idx++) {
            printf("%d\t", dp[idx]);
        }
        printf("\n");
    }
    return dp[target];
}

//#define CHANGE
#ifdef CHANGE
int main(int argc, char** argv)
{
    vector<int> nums{ 1,2,5 };
    int c1 = change(nums, 5);
    printf("change:%d\n", c1);

    int c2 = change2(nums, 5);
    printf("change2:%d\n", c2);

    getchar();
    return 0;
}
#endif // CHANGE
