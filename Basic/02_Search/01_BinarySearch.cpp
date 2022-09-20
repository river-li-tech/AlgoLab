#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
冒泡排序
*/
using namespace std;

//求任意一个i使得v[i]=v，不存在返回-1
int BinarySearch_Any(vector<int>& arr, int val)
{
    if (arr.size() == 0) return -1;

    int len = arr.size();
    //区间[left, right)
    int left = 0;
    int right = len;
    //结束条件：left=right
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == val) return mid;
        else if (arr[mid] < val) left = mid + 1;
        else if (arr[mid] > val) right = mid;
    }
    return -1;
}

//求最小的i使得v[i]=v，不存在返回-1
int BinarySearch_Min(vector<int>& arr, int val)
{
    if (arr.size() == 0) return -1;

    int len = arr.size();
    //区间[left, right)
    int left = 0;
    int right = len;
    //结束条件：left=right
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == val) return right = mid;
        else if (arr[mid] < val) left = mid + 1;
        else if (arr[mid] > val) right = mid;
    }
    return -1;
}

//#define BINARY_SEARCH
#ifdef BINARY_SEARCH
int main(int argc, char** argv)
{
    vector<int> arr{ 1, 2, 2, 3, 3, 5, 5, 7, 7, 7, 7, 10 };
    printf("search:%d\n", BinarySearch_Any(arr, 11));

    getchar();
    return 0;
}
#endif // BINARY_SEARCH
