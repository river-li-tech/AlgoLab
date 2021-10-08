#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <queue>

/*
»ùÊýÅÅÐò
*/
using namespace std;

void RadixSort(vector<int>& arr, int maxDigit)
{
    if (arr.size() <= 1) return;
    
    vector<queue<int>> buckets(10);
    int mod = 10;
    int dev = 1;
    int cidx = 0;
    for (size_t num = 0; num < maxDigit; num++, dev *=10, mod *=10) {
        for (auto val : arr) {
            int sval = (val % mod) / dev;
            buckets[sval].push(val);
        }
        cidx = 0;
        for (auto &bucket : buckets) {
            while (bucket.size() > 0) {
                arr[cidx++] = bucket.front();
                bucket.pop();
            }
        }
    }
}

//#define RADIX_SORT
#ifdef RADIX_SORT
int main(int argc, char** argv)
{
    vector<int> arr;
    srand((unsigned)time(NULL));
    for (size_t idx = 100000; idx > 0; idx--) {
        arr.push_back(idx);
    }
    //vector<int> arr{2, 41, 19, 0, 72, 33, 60, 11};
    clock_t start = clock();
    RadixSort(arr, 6);
    clock_t end = clock();
    printf("RadixSort Elapsed:%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    //for (auto num : arr) {
    //    printf("%d\t", num);
    //}
    printf("\n");

    getchar();
    return 0;
}
#endif // RADIX_SORT
