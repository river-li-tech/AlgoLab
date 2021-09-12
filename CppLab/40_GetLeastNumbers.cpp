#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>

/*
输入整数数组 arr ，找出其中最小的 k 个数。
例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
*/

#define GETLEASTNUMBERS

#ifdef GETLEASTNUMBERS
using namespace std;

//大头堆
vector<int> getLeastNumbers(vector<int>& arr, int k)
{
    vector<int> ret;
    if (arr.size() == 0 || k <= 0) return ret;
    //插入大头堆中
    priority_queue<int> queue;
    for (size_t idx = 0; idx < arr.size(); idx++) {
        if (queue.size() < k) {
            queue.push(arr[idx]);
            continue;
        }
        int max = queue.top();
        if (arr[idx] < max) {
            queue.pop();
            queue.push(arr[idx]);
        }
    }
    //导入到vector<int>
    while (!queue.empty()) {
        ret.push_back(queue.top());
        queue.pop();
    }
    return ret;
}

int main(int argc, char** argv)
{
    vector<int> vec{3, 2, 1};
    int k = 2;
    vector<int> ret = getLeastNumbers(vec, k);
    for_each(ret.begin(), ret.end(), [](int val) {printf("%d\t", val); });

    getchar();
    return 0;
}
#endif // GETLEASTNUMBERS

