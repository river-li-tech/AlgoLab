/*
88. 合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int idx = 0; idx < n; idx++)
        {
            nums1[idx + m] = nums2[idx];
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main()
{
    Solution sol;
    vector<int> nums1{4,5,6,0,0,0};
    vector<int> nums2{1,2,3};
    int m = 3;
    int n = 3;
    sol.merge(nums1, m, nums2, n);
    for_each(nums1.begin(), nums1.end(), [&](int& val) {
        cout << val << " ";
    });
}
