#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。
*/
using namespace std;
bool canJump(vector<int>& nums)
{
    if (nums.size() <= 1) return true;
    int maxdis = 0;
    for (int idx = 0; idx < nums.size() - 1; idx++) {
        maxdis = max(maxdis, idx + nums[idx]);
        if (maxdis == idx) return false;
        if (maxdis >= nums.size() - 1) return true;
    }
    return false;
}

//#define CAN_JUMP
#ifdef CAN_JUMP
int main(int argc, char** argv)
{
    //vector<int> nums{ 2,3,1,1,4 };
    //vector<int> nums{ 3,2,1,0,4 };
    vector<int> nums{ 0, 2, 3 };
    //vector<int> nums{ -1 };
    bool bjump = canJump(nums);
    printf("canJump:%s\n", bjump?"true":"false");

    getchar();
    return 0;
}
#endif // CAN_JUMP
