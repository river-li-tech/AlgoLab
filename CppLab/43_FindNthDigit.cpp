#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>

/*
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
要求时间复杂度为O(n)。
*/

//#define MAXSUBARRAY

#ifdef MAXSUBARRAY
using namespace std;
//动态规划
int maxSubArray(vector<int>& nums)
{
    int pre = 0, maxAns = nums[0];
    for (const auto& x : nums) {
        pre = max(pre + x, x);
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}



int main(int argc, char** argv)
{
    vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
    //vector<int> nums{ 4,-1,2,1 };
    int max = maxSubArray(nums);
    printf("maxSubArray:%d\n", max);

    getchar();
    return 0;
}
#endif // MAXSUBARRAY

