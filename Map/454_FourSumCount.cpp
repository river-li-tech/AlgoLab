#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <unordered_map>

/*
计算4数之和
*/

using namespace std;
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    unordered_map<int, int> maps;
    for (auto num1 : nums1) {
        for (auto num2 : nums2) {
            maps[num1 + num2]++;
        }
    }
    int count = 0;
    for (auto num3 : nums3) {
        for (auto num4 : nums4) {
            if (maps.find(0 - (num3 + num4)) != maps.end()) {
                count += maps[0 - (num3 + num4)];
            }
        }
    }
    return count;
}

//#define FOUR_SUM_COUNT
#ifdef FOUR_SUM_COUNT
int main(int argc, char** argv)
{
    vector<int> A = { 1, 2 };
    vector<int> B = { -2, -1 };
    vector<int> C = { -1, 2 };
    vector<int> D = { 0, 2 };

    int count = fourSumCount(A, B, C, D);
    printf("fourSumCount:%d\t", count);
    printf("\n");

    getchar();
    return 0;
}
#endif // FOUR_SUM_COUNT
