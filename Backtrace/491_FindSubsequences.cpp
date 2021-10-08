#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <stack>
#include <vector>
#include <unordered_set>

/*
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
*/
using namespace std;

vector<int> fspath;
vector<vector<int>> fsresult;
void findSubInternal(vector<int>& nums, int startIdx)
{
    //统计结果
    if (fspath.size() > 1) {
        fsresult.push_back(fspath);
    }
    //去重
    unordered_set<int> used;
    //递归
    for (int idx = startIdx; idx < nums.size(); idx++) {
        //同一父节点下的同层上使用过的元素就不能在使用了
        if (used.find(nums[idx]) != used.end()) {
            continue;
        }
        //剪枝：非递增序列可不再考虑
        if (fspath.size() >= 1 && nums[idx] < fspath.back()) {
            continue;
        }
        used.insert(nums[idx]);
        fspath.push_back(nums[idx]);
        findSubInternal(nums, idx + 1);
        fspath.pop_back();
    }
}
vector<vector<int>> findSubsequences(vector<int>& nums)
{
    fspath.clear();
    fsresult.clear();
    findSubInternal(nums, 0);
    return fsresult;
}

#define FIND_SUB_SEQUENCE
#ifdef FIND_SUB_SEQUENCE
int main(int argc, char** argv)
{
    vector<int> nums{4, 6, 7, 7};
    vector<vector<int>> fsresult = findSubsequences(nums);
    for (auto vec : fsresult) {
        for (auto num : vec) {
            printf("%d\t", num);
        }
        printf("\n");
    }

    getchar();
    return 0;
}
#endif // FIND_SUB_SEQUENCE
