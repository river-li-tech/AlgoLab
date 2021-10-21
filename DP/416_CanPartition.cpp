#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
分割等和子集
*/
using namespace std;

bool canPartition(vector<int>& nums)
{
    int total = 0;
    for (int idx = 0; idx < nums.size(); idx++) {
        total += nums[idx];
    }
    if (total % 2 != 0) return false;

    int target = total / 2;
    vector<int> dp(target + 1, 0);
    for (int itemIdx = 0; itemIdx < nums.size(); itemIdx++) {
        for (int bagIdx = target; bagIdx >= nums[itemIdx]; bagIdx--) {
            dp[bagIdx] = max(dp[bagIdx], dp[bagIdx - nums[itemIdx]] + nums[itemIdx]);
        }
    }
    return dp[target] == target;
}

//#define CAN_PARTITION
#ifdef CAN_PARTITION
int main(int argc, char** argv)
{
    vector<int> nums{ 1, 5, 11,5 };
    bool ret = canPartition(nums);
    printf("canPartition:%s\n", ret ? "true" : "false");

    getchar();
    return 0;
}
#endif // CAN_PARTITION
