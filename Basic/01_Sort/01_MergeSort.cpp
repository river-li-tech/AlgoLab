#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
归并排序
*/

using namespace std;
void MergeInternal(vector<int>& arr, int front, int mid, int end)
{
    //申请临时空间
    vector<int> leftArr(arr.begin() + front, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + end + 1);
    //从左右挑选
    int leftIdx = 0;
    int rightIdx = 0;
    int arrIdx = front;
    while (leftIdx < leftArr.size() && rightIdx < rightArr.size()) {
        if (leftArr[leftIdx] < rightArr[rightIdx]) {
            arr[arrIdx++] = leftArr[leftIdx++];
        } else {
            arr[arrIdx++] = rightArr[rightIdx++];
        }
    }
    //合并剩余部分
    while (leftIdx < leftArr.size()) {
        arr[arrIdx++] = leftArr[leftIdx++];
    }
    while (rightIdx < rightArr.size()) {
        arr[arrIdx++] = rightArr[rightIdx++];
    }
}

void MergeSortPartial(vector<int>& arr, int front, int end)
{
    if (front >= end) return;

    int mid = ((end - front) >> 1) + front;
    MergeSortPartial(arr, front, mid);
    MergeSortPartial(arr, mid + 1, end);
    MergeInternal(arr, front, mid, end);
}

void MergeSort(vector<int> &arr)
{
    if (arr.size() <= 1) return;
    MergeSortPartial(arr, 0, arr.size() - 1);
}

//#define MERGE_SORT
#ifdef MERGE_SORT
int main(int argc, char** argv)
{
    vector<int> arr;
    srand((unsigned)time(NULL));
    for (size_t idx = 1000; idx > 0; idx--) {
        arr.push_back(idx);
    }

    clock_t start = clock();
    MergeSort(arr);
    clock_t end = clock();
    printf("MergeSort Elapsed:%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    //for (auto num : arr) {
    //    printf("%d\t", num);
    //}
    //printf("\n");

    getchar();
    return 0;
}
#endif // MERGE_SORT
