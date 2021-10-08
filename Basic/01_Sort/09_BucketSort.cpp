#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
Õ∞≈≈–Ú
*/
using namespace std;

void BucketSort(vector<int>& arr, int bucketSize)
{
    if (arr.size() <= 1) return;
    
    int minVal = arr[0];
    int maxVal = arr[0];
    for (auto num : arr) {
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
    }

    int bucketCnt = (maxVal - minVal) / bucketSize;
    bucketCnt = max(bucketCnt, 1);
    vector<vector<int>> buckets(bucketCnt + 1);
    for (auto num : arr) {
        int bidx = (num - minVal) / bucketSize;
        buckets[bidx].push_back(num);
    }

    int cidx = 0;
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        for (size_t idx = 0; idx < bucket.size(); idx++) {
            arr[cidx++] = bucket[idx];
        }
    }
}

//#define BUCKET_SORT
#ifdef BUCKET_SORT
int main(int argc, char** argv)
{
    vector<int> arr;
    srand((unsigned)time(NULL));
    for (size_t idx = 100000; idx > 0; idx--) {
        arr.push_back(idx);
    }
    //vector<int> arr{20, 40, 12, 0, 71, 39, 61, 3};
    clock_t start = clock();
    BucketSort(arr, 1000);
    clock_t end = clock();
    printf("BucketSort Elapsed:%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    //for (auto num : arr) {
    //    printf("%d\t", num);
    //}
    printf("\n");

    getchar();
    return 0;
}
#endif // BUCKET_SORT
