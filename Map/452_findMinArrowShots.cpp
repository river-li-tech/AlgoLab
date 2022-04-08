#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <deque>
#include <vector>
#include <queue>
#include <unordered_map>

/*
前 K 个高频元素
*/

using namespace std;
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

//#define FIND_MIN_ARROW_SHOTS
#ifdef FIND_MIN_ARROW_SHOTS
int main(int argc, char** argv)
{
    vector<vector<int>> points{
        //{10,16},{2,8},{1,6},{7,12}
        {1,2} ,{3,4},{5,6},{7,8}
    };
    int ret = findMinArrowShots(points);
    printf("findMinArrowShots:%d\n", ret);

    getchar();
    return 0;
}
#endif // FIND_MIN_ARROW_SHOTS
