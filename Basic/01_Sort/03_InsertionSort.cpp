#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
≤Â»Î≈≈–Ú
*/
using namespace std;

void InsertionSort(vector<int>& arr)
{
    if (arr.size() <= 1) return;

    int len = arr.size();
    int curVal = 0;
    int preIdx = 0;
    for (size_t i = 1; i < len; i++) {
        curVal = arr[i];
        preIdx = i - 1;
        while (preIdx >= 0 && arr[preIdx] > curVal) {
            arr[preIdx + 1] = arr[preIdx];
            preIdx--;
        }
        arr[preIdx + 1] = curVal;
    }
}

//#define INSERTION_SORT
#ifdef INSERTION_SORT
int main(int argc, char** argv)
{
    //vector<int> arr;
    //srand((unsigned)time(NULL));
    //for (size_t idx = 10; idx > 0; idx--) {
    //    arr.push_back(idx);
    //}
    vector<int> arr{2, 4, 1, 0, 7, 3, 6, 1};
    clock_t start = clock();
    InsertionSort(arr);
    clock_t end = clock();
    printf("InsertionSort Elapsed:%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (auto num : arr) {
        printf("%d\t", num);
    }
    //printf("\n");

    getchar();
    return 0;
}
#endif // INSERTION_SORT
