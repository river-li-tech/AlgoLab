#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <stack>
#include <vector>

/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/
using namespace std;

vector<int> subsetPath;
vector<vector<int>> subsetResult;
void subsetsBackbtrace(vector<int>& nums, int startIdx)
{
    //添加所有节点
    subsetResult.push_back(subsetPath);
    //终止条件可以不加
    if (nums.size() <= startIdx) {
        return;
    }
    //递归
    for (int idx = startIdx; idx < nums.size(); idx++) {
        subsetPath.push_back(nums[idx]);
        subsetsBackbtrace(nums, idx + 1);
        subsetPath.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums)
{
    subsetResult.clear();
    subsetPath.clear();
    subsetsBackbtrace(nums, 0);
    return subsetResult;
}

//#define SUBSETS
#ifdef SUBSETS
int main(int argc, char** argv)
{
    vector<int> nums{ 1, 2, 3 };
    vector<vector<int>> subsetResult = subsets(nums);
    for (auto vec : subsetResult) {
        for (auto num : vec) {
            printf("%d\t", num);
        }
        printf("\n");
    }

    getchar();
    return 0;
}
#endif // SUBSETS
