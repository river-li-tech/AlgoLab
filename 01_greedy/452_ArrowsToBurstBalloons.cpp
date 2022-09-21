/*
452. 用最少数量的箭引爆气球
有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points)
  {
      if (points.size() <= 1) return points.size();

      sort(points.begin(), points.end(), [](vector<int>& left, vector<int>& right)->bool {return left[0] < right[0]; });
      int range = points[0][1];
      int count = 1;
      for (int idx = 1; idx < points.size(); idx++)
      {
          vector<int>& point = points[idx];
          if (point[0] > range) {
              count++;
              range = point[1];
          } else {
              range = min(range, point[1]);
          }
      }
      return count;
  }
};

int main()
{
    Solution sol;
    vector<vector<int>> points{{10,16},{2,8},{1,6},{7,12}};
    int n = 2;
    int ret = sol.findMinArrowShots(points);
    cout << "findMinArrowShots: " << ret << endl;
}
