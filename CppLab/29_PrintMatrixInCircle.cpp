#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
*/

//#define PRINTMATRIXINCIRCLE

#ifdef PRINTMATRIXINCIRCLE
using namespace std;

void GetMatrixCircle(vector<vector<int>>& matrix, vector<int>& list, int rows, int cols, int start)
{
    int endX = cols - start - 1;
    int endY = rows - start - 1;
    //leftTop->rightTop
    for (int idx = start; idx <= endX; idx++) {
        list.push_back(matrix[start][idx]);
    }
    //rightTop->rightBottom
    if (start < endY) {
        for (int idx = start + 1; idx <= endY; idx++) {
            list.push_back(matrix[idx][endX]);
        }
    }
    //rightBottom->leftBottom
    if (endX > start && endY > start) {
        for (int idx = endX - 1; idx >= start; idx--) {
            list.push_back(matrix[endY][idx]);
        }
    }
    //leftBottom->leftTop
    if (start < endX && start < endY - 1) {
        for (int idx = endY - 1; idx >= start + 1; idx--) {
            list.push_back(matrix[idx][start]);
        }
    }
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> list;
    
    int rows = matrix.size();
    if (rows == 0) return list;
    int cols = matrix[0].size();
    if (cols == 0) return list;

    int start = 0;
    while (start * 2 < rows && start * 2 < cols) {
        GetMatrixCircle(matrix, list, rows, cols, start);
        start++;
    }
    return list;
}

int main(int argc, char** argv)
{
    vector<vector<int>> matrix = { 
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9} 
    };

    vector<int> list = spiralOrder(matrix);
    for (size_t idx = 0; idx < list.size(); idx++) {
        printf("%d\t", list[idx]);
    }

    getchar();
    return 0;
}
#endif // PRINTMATRIXINCIRCLE
