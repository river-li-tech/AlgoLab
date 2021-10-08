#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？
*/
using namespace std;

/////////////////////////////////////////////////////////////
//回溯法DFS
int uniquePathsBt(int m, int n, int r, int c, vector<int>& memo)
{
    if (r > m || c > n) {
        return 0;
    }
    if (r == m && c == n) {
        return 1;
    }
    if (memo[r * n + c] != 0) {
        return memo[r * n + c];
    }
    int sum = uniquePathsBt(m, n, r + 1, c, memo);
    sum += uniquePathsBt(m, n, r, c + 1, memo);
    memo[r * n + c] = sum;
    return sum;
}
int uniquePathsDFS(int m, int n)
{
    vector<int> memo((m + 1) * (n + 1), 0);
    return uniquePathsBt(m, n, 1, 1, memo);
}

//DP
int uniquePaths(int m, int n)
{
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

//#define UNIQUE_PATHS
#ifdef UNIQUE_PATHS
int main(int argc, char** argv)
{
    {
        int path = uniquePathsDFS(3, 7);
        printf("dfs %d,%d=>%d\n", 3, 7, path);

        int path2 = uniquePathsDFS(3, 2);
        printf("dfs %d,%d=>%d\n", 3, 2, path2);

        int path3 = uniquePathsDFS(36, 7);
        printf("dfs %d,%d=>%d\n", 36, 7, path3);
    }

    {
        int path = uniquePaths(3, 7);
        printf("dp %d,%d=>%d\n", 3, 7, path);

        int path2 = uniquePaths(3, 2);
        printf("dp %d,%d=>%d\n", 3, 2, path2);

        int path3 = uniquePaths(36, 7);
        printf("dp %d,%d=>%d\n", 36, 7, path3);
    }

    getchar();
    return 0;
}
#endif // UNIQUE_PATHS
