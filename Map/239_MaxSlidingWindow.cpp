#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <deque>
#include <vector>
#include <queue>

/*
滑动窗口最大值
*/

using namespace std;

//优先队列算法
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> ret;
    priority_queue<pair<int, int>> queue;
    for (int idx = 0; idx < k; idx++) {
        queue.push({nums[idx], idx});
    }
    ret.push_back(queue.top().first);

    for (int idx = k; idx < nums.size(); idx++) {
        queue.push({ nums[idx], idx });
        while (queue.top().second <= (idx - k)) {
            queue.pop();
        }
        ret.push_back(queue.top().first);
    }
    return ret;
}

//单调队列算法
vector<int> maxSlidingWindow2(vector<int>& nums, int k)
{
    vector<int> ret;
    deque<int> idxs;

    //单调压入前K个数
    for (int idx = 0; idx < k; idx++) {
        while (!idxs.empty() && nums[idx] >= nums[idxs.back()]) {
            idxs.pop_back();
        }
        idxs.push_back(idx);
    }
    ret.push_back(nums[idxs.front()]);

    for (int idx = k; idx < nums.size(); idx++) {
        //单调压入
        while (!idxs.empty() && nums[idx] >= nums[idxs.back()]) {
            idxs.pop_back();
        }
        idxs.push_back(idx);
        //检查左边界
        while (idxs.front() <= idx - k) {
            idxs.pop_front();
        }
        ret.push_back(nums[idxs.front()]);
    }
    return ret;
}

//#define MAX_SLIDING_WINDOW
#ifdef MAX_SLIDING_WINDOW
int main(int argc, char** argv)
{
    vector<int> nums{ 7, 2, 4 };
    int k = 2;
    vector<int> ret = maxSlidingWindow(nums, k);
    for (auto num : ret) {
        printf("%d\t", num);
    }

    getchar();
    return 0;
}
#endif // MAX_SLIDING_WINDOW
