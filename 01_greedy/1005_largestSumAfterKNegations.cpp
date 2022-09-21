#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。（我们可以多次选择同一个索引 i。）

以这种方式修改数组后，返回数组可能的最大和。
*/
using namespace std;
int largestSumAfterKNegations(vector<int>& nums, int k)
{
    int len = nums.size();
    sort(nums.begin(), nums.end(), [](int left, int right)-> bool {return abs(left) > abs(right); });
    for (int idx = 0; idx < len; idx++) {
        if (nums[idx] < 0 && k > 0) {
            nums[idx] *= -1;
            k--;
        }
    }
    if (k % 2 == 1) nums[len - 1] *= -1;
    int sum = 0;
    for (int idx = 0; idx < len; idx++) {
        sum += nums[idx];
    }
    return sum;
}

//#define LARGEST_SUM_AFTER_K_NEGATIONS
#ifdef LARGEST_SUM_AFTER_K_NEGATIONS
int main(int argc, char** argv)
{
    vector<int> nums{ 2,-3,-1,5,-4 };
    int k = 2;
    //vector<int> nums{ -1 };
    int sum = largestSumAfterKNegations(nums, k);
    printf("largestSumAfterKNegations:%d\n", sum);

    getchar();
    return 0;
}
#endif // LARGEST_SUM_AFTER_K_NEGATIONS
