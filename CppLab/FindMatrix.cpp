#include <cstdio>
#include <cstdlib>
#include <vector>

//#define FINDMATRIX

#ifdef FINDMATRIX
using namespace std;
bool FindMatrix(vector<vector<int>>& vec, int num)
{
    int rows = vec.size();
    int cols = vec[0].size();

    if (rows > 0 && cols > 0) {

        int row = 0;
        int col = cols - 1;
        while (row < rows && col >= 0) {
            if (vec[row][col] == num) {
                return true;
            } else if (vec[row][col] > num) {
                col--;
            } else {
                row++;
            }
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
    vector<vector<int>> vec{
        {1,   4,  7, 11, 15} ,
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int num = 14;
    bool find = FindMatrix(vec, num);
    printf("FindMatrix:%d ret:%s\n", num, find? "true": "false");
    getchar();

    return 0;
}
#endif // FINDMATRIX
