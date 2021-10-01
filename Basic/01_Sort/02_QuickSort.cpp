#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
øÏÀŸ≈≈–Ú
*/
using namespace std;

int QuickSortPartition(vector<int>& arr, int left, int right)
{
    int pivot = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= pivot) {
            right--;
        }
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot) {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}

void QuickSortInternal(vector<int>& arr, int left, int right)
{
    if (left < right) {
        int pivot = QuickSortPartition(arr, left, right);
        QuickSortInternal(arr, left, pivot - 1);
        QuickSortInternal(arr, pivot + 1, right);
    }
}

void QuickSort(vector<int>& arr)
{
    if (arr.size() <= 1) return;
    QuickSortInternal(arr, 0, arr.size() - 1);
}

//#define QUICK_SORT
#ifdef QUICK_SORT
int main(int argc, char** argv)
{
    vector<int> arr;
    srand((unsigned)time(NULL));
    for (size_t idx = 1000; idx > 0; idx--) {
        arr.push_back(idx);
    }
    //vector<int> arr{2, 4, 1, 0, 7, 3, 6, 1};
    clock_t start = clock();
    QuickSort(arr);
    clock_t end = clock();
    printf("QuickSort Elapsed:%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    //for (auto num : arr) {
    //    printf("%d\t", num);
    //}
    //printf("\n");

    getchar();
    return 0;
}
#endif // QUICK_SORT
