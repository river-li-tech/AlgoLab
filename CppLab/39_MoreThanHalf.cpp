#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>

/*
数组中出现次数超过一半的数字
*/

//#define MORETHANHALF

#ifdef MORETHANHALF
using namespace std;
//积分算法
int MoreThanHalf(vector<int>& vec)
{
    if (vec.size() == 0) return 0;

    int curNum = vec[0];
    int cnt = 1;
    for (size_t idx = 1; idx < vec.size(); idx++) {
        if (cnt == 0) {
            curNum = vec[idx];
            cnt = 1;
        } else {
            if (vec[idx] == curNum) cnt++;
            else cnt--;
        }
    }
    return curNum;
}
//中位数法
int MoreThanHalf2(vector<int>& vec)
{
    if (vec.size() == 0) return 0;
    sort(vec.begin(), vec.end());
    return vec[vec.size() / 2];
}
//分治法
int GetTimes(vector<int>& vec, int start, int end, int val) {
    int cnt = 0;
    for (size_t idx = start; idx < end; idx++) {
        if (vec[idx] == val) cnt++;
    }
    return cnt;
};
int MoreThanHalfInternal3(vector<int>& vec, int start, int end)
{
    if (start == end) return vec[start];

    int middle = ((end - start) >> 1) + start;
    int left = MoreThanHalfInternal3(vec, start, middle);
    int right = MoreThanHalfInternal3(vec, middle + 1, end);
    if (left == right) return left;

    int leftCnt = GetTimes(vec, start, end, left);
    int rightCnt = GetTimes(vec, start, end, right);
    return (leftCnt > rightCnt) ? left : right;
}
int MoreThanHalf3(vector<int>& vec)
{
    if (vec.size() == 0) return 0;
    return MoreThanHalfInternal3(vec, 0, vec.size() - 1);
}

int main(int argc, char** argv)
{
    vector<int> vec{2, 3, 4, 5, 4, 2, 2, 2, 4, 2, 2};
    {
        int num = MoreThanHalf(vec);
        printf("MoreThanHalf:%d\n", num);
    }
    {
        int num = MoreThanHalf2(vec);
        printf("MoreThanHalf:%d\n", num);
    }
    {
        int num = MoreThanHalf3(vec);
        printf("MoreThanHalf:%d\n", num);
    }
    getchar();
    return 0;
}
#endif // MORETHANHALF
