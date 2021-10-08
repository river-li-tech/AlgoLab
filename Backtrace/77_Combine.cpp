#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <stack>
#include <vector>

/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
*/
using namespace std;

vector<int> path;
vector<vector<int>> result;
void backtrace(int n, int k, int startIdx)
{
    //终止条件
    if (path.size() == k) {
        result.push_back(path);
        return;
    }
    //递归
    //剪枝：剩余数不足

    for (int idx = startIdx; idx <= n - (k - path.size()) + 1; idx++) {
        path.push_back(idx);
        backtrace(n, k, idx + 1);
        path.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    path.clear();
    result.clear();
    backtrace(n, k, 1);
    return result;
}

//#define COMBINE
#ifdef COMBINE
int main(int argc, char** argv)
{
    int n = 4;
    int k = 2;
    vector<vector<int>> result = combine(n, k);
    for (auto vec : result) {
        for (auto num : vec) {
            printf("%d\t", num);
        }
        printf("\n");
    }

    getchar();
    return 0;
}
#endif // COMBINE
