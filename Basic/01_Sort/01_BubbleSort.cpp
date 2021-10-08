#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
√∞≈›≈≈–Ú
*/
using namespace std;

void BubbleSort(vector<int>& arr)
{
    if (arr.size() <= 1) return;
    int len = arr.size();
    for (size_t i = 0; i < len - 1; i++) {
        for (size_t j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//#define BUBBLE_SORT
#ifdef BUBBLE_SORT
int main(int argc, char** argv)
{
    vector<int> arr;
    srand((unsigned)time(NULL));
    for (size_t idx = 1000; idx > 0; idx--) {
        arr.push_back(idx);
    }
    //vector<int> arr{2, 4, 1, 0, 7, 3, 6, 1    
    clock_t start = clock();
    BubbleSort(arr);
    clock_t end = clock();
    printf("BubbleSort Elapsed:%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    //for (auto num : arr) {
    //    printf("%d\t", num);
    //}
    //printf("\n");

    getchar();
    return 0;
}
#endif // BUBBLE_SORT
