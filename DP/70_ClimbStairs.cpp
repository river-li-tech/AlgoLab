#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
爬梯子
*/
using namespace std;

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/
int climbStairs(int n)
{
    int dp[3] = {0, 1, 2};
    if (n <= 2) return dp[n];

    int sum = 0;
    for (int idx = 3; idx <= n; idx++) {
        sum = dp[2] + dp[1];
        dp[1] = dp[2];
        dp[2] = sum;
    }
    return dp[2];
}

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1-m台阶。你有多少种不同的方法可以爬到楼顶呢？
*/
int climbStairs2(int n, int m)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i >= j) {
                dp[i] += dp[i - j];
            } else {
                break;
            }
        }
    }
    return dp[n];
}

//#define CLIMB_STAIRS
#ifdef CLIMB_STAIRS
int main(int argc, char** argv)
{
    {
        int stairs = climbStairs(5);
        printf("climbStairs %d:%d\n", 5, stairs);
    }

    {
        int stairs = climbStairs2(5, 2);
        printf("climbStairs2 %d/%d:%d\n", 5, 2, stairs);
    }
    getchar();
    return 0;
}
#endif // CLIMB_STAIRS
