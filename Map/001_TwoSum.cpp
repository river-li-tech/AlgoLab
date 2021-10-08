#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <unordered_map>

/*
计算2数之和
*/

using namespace std;
vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> numsMap;
    for (int idx = 0; idx < nums.size(); idx++) {
        auto iter = numsMap.find(target - nums[idx]);
        if (iter != numsMap.end()) {
            return { idx, iter->second };
        }
        numsMap.insert({ nums[idx], idx });
    }
    return {};
}

//#define TWO_SUM
#ifdef TWO_SUM
int main(int argc, char** argv)
{
    vector<int> nums{ 2,7,11,15 };
    int target = 9;
    vector<int> ret = twoSum(nums, target);

    for (auto num : ret) {
        printf("%d\t", num);
    }
    printf("\n");

    getchar();
    return 0;
}
#endif // TWO_SUM
