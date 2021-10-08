#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
¼ÆÊýÅÅÐò
*/
using namespace std;

void CountSort(vector<int>& arr, int maxVal)
{
    if (arr.size() <= 1) return;
    
    vector<int> buckets(maxVal + 1, 0);
    for (auto num : arr) {
        buckets[num]++;
    }
    int sidx = 0;
    for (int idx = 0; idx < buckets.size(); idx++) {
        while (buckets[idx] > 0) {
            arr[sidx++] = idx;
            buckets[idx]--;
        }
    }
}

//#define COUNT_SORT
#ifdef COUNT_SORT
int main(int argc, char** argv)
{
    //vector<int> arr;
    //srand((unsigned)time(NULL));
    //for (size_t idx = 10; idx > 0; idx--) {
    //    arr.push_back(idx);
    //}
    vector<int> arr{2, 4, 1, 0, 7, 3, 6, 1};
    clock_t start = clock();
    CountSort(arr, 7);
    clock_t end = clock();
    printf("CountSort Elapsed:%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (auto num : arr) {
        printf("%d\t", num);
    }
    printf("\n");

    getchar();
    return 0;
}
#endif // COUNT_SORT
