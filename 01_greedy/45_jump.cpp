#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。
*/
using namespace std;
int jump(vector<int>& nums)
{
    if (nums.size() <= 1) return 0;

    int count = 0;
    int curdis = 0, maxdis = 0;
    for (int idx = 0; idx <= nums.size() - 1; idx++) {
        maxdis = max(maxdis, idx + nums[idx]);
        if (maxdis >= nums.size() - 1) {
            count++;
            break;
        }
        if (idx == curdis) {
            count++;
            curdis = maxdis;
        }
    }
    return count;
}

//#define JUMP
#ifdef JUMP
int main(int argc, char** argv)
{
    vector<int> nums{ 2,3,1,1,4 };
    //vector<int> nums{ 3,2,1,0,4 };
    //vector<int> nums{ 1, 2, 3 };
    //vector<int> nums{ -1 };
    //vector<int> nums{ 0 };
    int ret = jump(nums);
    printf("jump:%d\n", ret);

    getchar();
    return 0;
}
#endif // JUMP
