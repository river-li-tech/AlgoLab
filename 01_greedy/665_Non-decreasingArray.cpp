/*
665. 非递减数列
给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <= 1) return true;

        int cnt = 0;
        if (nums[0] > nums[1]) {
            nums[0] = nums[1];
            cnt++;
        }
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] < nums[i]) {
                if (nums[i + 1] < nums[i - 1]) {
                    nums[i + 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
                cnt++;
            }
        }
        return cnt <= 1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{3,4,2,3};
    bool ret = sol.checkPossibility(nums);
    cout << "checkPossibility:" << (ret ? "true" : "false") << endl;
    return 0; 
}
