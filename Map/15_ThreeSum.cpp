#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <unordered_map>

/*
计算3数之和
*/

using namespace std;
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> ret;
    if (nums.size() < 3) {
        return ret;
    }

    sort(nums.begin(), nums.end());
    for (int idx = 0; idx < nums.size() - 2; idx++) {
        if (idx > 0 && nums[idx] == nums[idx - 1]) {
            continue;
        }
        int left = idx + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[idx] + nums[left] + nums[right];
            if (sum == 0) {
                ret.push_back({ nums[idx], nums[left], nums[right] });
                //去重
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum > 0) {//过大则右边收缩
                right--;
            } else if (sum < 0) {//过小则左边收缩
                left++;
            }
        }
    }
    return ret;
}

//#define THREE_SUM
#ifdef THREE_SUM
int main(int argc, char** argv)
{
    vector<int> nums = { -1,0,1,2,-1,-4 };
    vector<vector<int>> ret = threeSum(nums);
    for (auto vec : ret) {
        for (auto num : vec) {
            printf("%d\t", num);
        }
        printf("\n");
    }

    getchar();
    return 0;
}
#endif // THREE_SUM
