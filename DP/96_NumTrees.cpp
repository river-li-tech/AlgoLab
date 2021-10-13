#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
*/
using namespace std;
int numTrees(int n)
{
    if (n <= 0) return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;//dp[0]也参与运算
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

//#define INTEGER_BREAK
#ifdef INTEGER_BREAK
int main(int argc, char** argv)
{
    printf("numTrees:%d=>%d\n", 3, numTrees(3));
    
    getchar();
    return 0;
}
#endif // INTEGER_BREAK
