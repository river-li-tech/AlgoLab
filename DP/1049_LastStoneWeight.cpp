#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
最后一块石头的重量 II
*/
using namespace std;
int lastStoneWeightII(vector<int>& stones)
{
    int total = 0;
    for (int idx = 0; idx < stones.size(); idx++) {
        total += stones[idx];
    }

    int target = total / 2;
    vector<int> dp(target + 1, 0);
    for (int itemIdx = 0; itemIdx < stones.size(); itemIdx++) {
        for (int bagIdx = target; bagIdx >= stones[itemIdx]; bagIdx--) {
            dp[bagIdx] = max(dp[bagIdx], dp[bagIdx - stones[itemIdx]] + stones[itemIdx]);
        }
    }
    return total - dp[target] * 2;
}

//#define LAST_STONE_WEIGHT
#ifdef LAST_STONE_WEIGHT
int main(int argc, char** argv)
{
    vector<int> nums{ 2,7,4,1,8,1 };
    int weight = lastStoneWeightII(nums);
    printf("lastStoneWeightII:%d\n", weight);

    getchar();
    return 0;
}
#endif // LAST_STONE_WEIGHT
