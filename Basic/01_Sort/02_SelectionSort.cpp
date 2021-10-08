#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
—°‘Ò≈≈–Ú
*/
using namespace std;

void SelectionSort(vector<int>& arr)
{
    if (arr.size() <= 1) return;
    int len = arr.size();
    int minIdx = 0;
    for (size_t i = 0; i < len - 1; i++) {
        minIdx = i;
        for (size_t j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
}

//#define SELECTION_SORT
#ifdef SELECTION_SORT
int main(int argc, char** argv)
{
    vector<int> arr;
    srand((unsigned)time(NULL));
    for (size_t idx = 1000; idx > 0; idx--) {
        arr.push_back(idx);
    }
    //vector<int> arr{2, 4, 1, 0, 7, 3, 6, 1};
    clock_t start = clock();
    SelectionSort(arr);
    clock_t end = clock();
    printf("SelectionSort Elapsed:%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    //for (auto num : arr) {
    //    printf("%d\t", num);
    //}
    //printf("\n");

    getchar();
    return 0;
}
#endif // SELECTION_SORT
