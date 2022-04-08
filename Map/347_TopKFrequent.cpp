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
//自定义小头堆，priority_queue默认为大头堆
static bool cmp(pair<int, int>& left, pair<int, int>& right)
{
    return left.second > right.second;
}

vector<int> topKFrequent(vector<int>& nums, int k)
{
    vector<int> ret;
    //保存到字典map，统计出现次数
    unordered_map<int, int> map;
    for (auto num : nums) {
        map[num]++;
    }
    //用小头堆插入前k个
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> queue(cmp);
    for (auto pair : map) {
        if (queue.size() >= k) {
            if (queue.top().second < pair.second) {
                queue.pop();
                queue.push({ pair.first, pair.second });
            }
        } else {
            queue.push({pair.first, pair.second});
        }
    }
    //转换位vector输出
    while (!queue.empty()) {
        ret.push_back(queue.top().first);
        queue.pop();
    }
    return ret;
}

//#define TOPK_FREQUENT
#ifdef TOPK_FREQUENT
int main(int argc, char** argv)
{
    vector<int> nums{ 1,1,1,2,2,3 };
    int k = 2;
    vector<int> ret = topKFrequent(nums, k);
    for (auto num : ret) {
        printf("%d\t", num);
    }

    getchar();
    return 0;
}
#endif // TOPK_FREQUENT
