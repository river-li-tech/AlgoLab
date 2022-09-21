/*
435. 无重叠区间
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 0) return 0;

        sort(intervals.begin(), intervals.end(), 
            [](vector<int>& a, vector<int>& b) { return a[1] < b[1];});

        int len = intervals.size();
        int prev = intervals[0][1];
        int removed = 0;
        for (int idx = 1; idx < len; idx++)
        {
            if (intervals[idx][0] < prev) {
                removed++;
            } else {
                prev = intervals[idx][1];
            }
        }
        return removed;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals{{1,2},{2,3},{3,4},{1,3}};
    int ret = sol.eraseOverlapIntervals(intervals);
    cout << "removed: " << ret << endl;
    return 0; 
}
