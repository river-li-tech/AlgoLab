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
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
*/
using namespace std;

/////////////////////////////////////////////////////////////
//回溯法DFS
int uniquePathsWithObstaclesBt(int m, int n, int r, int c, vector<vector<int>>& obstacleGrid, vector<vector<int>>& memo)
{
    if (r >= m || c >= n) {
        return 0;
    }
    if (obstacleGrid[r][c] == 1) {
        return 0;
    }
    if (r == m - 1 && c == n - 1) {
        return 1;
    }
    if (memo[r][c] != 0) {
        return memo[r][c];
    }
    int sum = uniquePathsWithObstaclesBt(m, n, r + 1, c, obstacleGrid, memo);
    sum += uniquePathsWithObstaclesBt(m, n, r, c + 1, obstacleGrid, memo);
    memo[r][c] = sum;
    return sum;
}
int uniquePathsWithObstaclesDFS(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> memo(m, vector<int>(n, 0));
    return uniquePathsWithObstaclesBt(m, n, 0, 0, obstacleGrid, memo);
}

//DP
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    //初始化
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
    for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
    //从左往右遍历
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

#define UNIQUE_PATHS_WITH_OBSTACLES
#ifdef UNIQUE_PATHS_WITH_OBSTACLES
int main(int argc, char** argv)
{
    vector<vector<int>> obstacleGrid = { {0, 0, 0},{0, 1, 0},{0, 0, 0} };

    {
        int path = uniquePathsWithObstaclesDFS(obstacleGrid);
        printf("dfs %d,%d=>%d\n", 3, 7, path);

        int path2 = uniquePathsWithObstaclesDFS(obstacleGrid);
        printf("dfs %d,%d=>%d\n", 3, 2, path2);

        int path3 = uniquePathsWithObstaclesDFS(obstacleGrid);
        printf("dfs %d,%d=>%d\n", 36, 7, path3);
    }

    {
        int path = uniquePathsWithObstacles(obstacleGrid);
        printf("dp %d,%d=>%d\n", 3, 7, path);

        int path2 = uniquePathsWithObstacles(obstacleGrid);
        printf("dp %d,%d=>%d\n", 3, 2, path2);

        int path3 = uniquePathsWithObstacles(obstacleGrid);
        printf("dp %d,%d=>%d\n", 36, 7, path3);
    }

    getchar();
    return 0;
}
#endif // UNIQUE_PATHS_WITH_OBSTACLES
