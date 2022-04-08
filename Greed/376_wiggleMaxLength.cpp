#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。
子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。

给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度
*/
using namespace std;
int wiggleMaxLength(vector<int>& nums)
{
    if (nums.size() <= 1) return nums.size();
    int length = 1;
    int diff = 0, lastdiff = 0;
    for (int idx = 1; idx < nums.size(); idx++) {
        diff = nums[idx] - nums[idx - 1];
        if ((diff > 0 && lastdiff <= 0) || (diff < 0 && lastdiff >= 0)) {
            length++;
            lastdiff = diff;
        }
    }
    return length;
}

//#define WIGGLE_MAX_LENGTH
#ifdef WIGGLE_MAX_LENGTH
int main(int argc, char** argv)
{
    vector<int> nums{ 1,17,5,10,13,15,10,5,16,8 };
    int length = wiggleMaxLength(nums);
    printf("wiggleMaxLength:%d\n", length);

    getchar();
    return 0;
}
#endif // WIGGLE_MAX_LENGTH
