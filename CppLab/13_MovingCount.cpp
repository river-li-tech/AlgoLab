#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
=> 回溯法，类似广度优先遍历
*/

//#define MOVINGCOUNT

#ifdef MOVINGCOUNT
using namespace std;

int CalcDigitSum(int num)
{
    if (num <= 0) return 0;
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

int CalcMovingCount(int rows, int cols, int row, int col, int k, bool* visited)
{
    if (row < 0 || col < 0 || row >= rows || col >= cols) {
        return 0;
    }
    //计算当前位置数位和
    int dsum = CalcDigitSum(row) + CalcDigitSum(col);

    //检查位置条件
    if (!visited[row * cols + col] && dsum <= k) {
        visited[row * cols + col] = true;
        return 1
            + CalcMovingCount(rows, cols, row + 1, col, k, visited)
            + CalcMovingCount(rows, cols, row - 1, col, k, visited)
            + CalcMovingCount(rows, cols, row, col + 1, k, visited)
            + CalcMovingCount(rows, cols, row, col - 1, k, visited);
    }
    return 0;
}

int movingCount(int m, int n, int k)
{
    if (m <= 0 || n <= 0 || k < 0) {
        return 0;
    }

    bool* visited = new bool[m * n];
    memset(visited, false, m * n);

    int count = CalcMovingCount(m, n, 0, 0, k, visited);
    delete [] visited;
    return count;
}

void testMovingCount(int rows, int cols, int k)
{
    int count = movingCount(rows, cols, k);
    printf("Moving rows(%d),cols(%d),k(%d)=> count(%d)\n", rows, cols, k, count);
}

int main(int argc, char** argv)
{
    testMovingCount(2, 2, 1);
    testMovingCount(2, 3, 1);
    testMovingCount(3, 1, 0);

    getchar();
    return 0;
}
#endif // MOVINGCOUNT
