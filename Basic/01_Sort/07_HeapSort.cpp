#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
堆排序
*/
using namespace std;

void HeapHeapify(vector<int>& arr, int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        //取son的2个子节点中更大的
        if (son < end && arr[son] < arr[son + 1]) {
            son++;
        }
        //对比son和dad节点关系是否满足大头堆
        if (arr[dad] > arr[son]) {
            return;
        } else {
            swap(arr[dad], arr[son]);
            //往下构建
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

//堆排序三步骤：大头、置换、重构
void HeapSort(vector<int>& arr)
{
    if (arr.size() <= 1) return;

    int len = arr.size();
    //构建大头堆(从len/2-1开始往上）
    for (int idx = len / 2 - 1; idx >= 0; idx--) {
        HeapHeapify(arr, idx, len - 1);
    }
    //提取+构建
    for (int idx = len - 1; idx > 0; idx--) {
        //置换出最大元素 0 <-> len-1
        swap(arr[0], arr[idx]);
        //重新构建出大头堆(从堆顶开始往下)
        HeapHeapify(arr, 0, idx - 1);
    }
}

//#define HEAP_SORT
#ifdef HEAP_SORT
int main(int argc, char** argv)
{
    //vector<int> arr;
    //for (size_t idx = 100000; idx > 0; idx--) {
    //    arr.push_back(idx);
    //}
    srand((unsigned)time(NULL));
    vector<int> arr{20, 40, 12, 0, 71, 39, 61, 3};
    clock_t start = clock();
    HeapSort(arr);
    clock_t end = clock();
    printf("HeapSort Elapsed:%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (auto num : arr) {
        printf("%d\t", num);
    }
    printf("\n");

    getchar();
    return 0;
}
#endif // HEAP_SORT
