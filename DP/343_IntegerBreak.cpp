#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
*/
using namespace std;

int integerBreak(int n)
{
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        }
    }
    return dp[n];
}

//#define INTEGER_BREAK
#ifdef INTEGER_BREAK
int main(int argc, char** argv)
{
    int brk = 10;
    printf("integerBreak:%d=>%d\n", 10, integerBreak(10));
    
    getchar();
    return 0;
}
#endif // INTEGER_BREAK
