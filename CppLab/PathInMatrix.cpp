#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

/**
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
*/

#define PATHINMATRIX

#ifdef PATHINMATRIX
using namespace std;

bool dfs(vector<vector<char>>& board, int rows, int cols, int row, int col, 
    vector<vector<bool>>& visited, string word, int& wordIdx)
{
    if (wordIdx == word.size()) {
        return true;
    }
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return false;
    }
    
    if (board[row][col] == word[wordIdx] && !visited[row][col]) {
        //先标记
        wordIdx++;
        visited[row][col] = true;

        //递归搜索4个方向
        bool bfind = dfs(board, rows, cols, row - 1, col, visited, word, wordIdx)
            || dfs(board, rows, cols, row + 1, col, visited, word, wordIdx)
            || dfs(board, rows, cols, row, col - 1, visited, word, wordIdx)
            || dfs(board, rows, cols, row, col + 1, visited, word, wordIdx);
        if (!bfind) {
            //撤回标记
            wordIdx--;
            visited[row][col] = false;
        }
        return bfind;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word)
{
    if (word.empty() || board.size() == 0 || board[0].size() == 0) {
        return false;
    }

    int rows = board.size();
    int cols = board[0].size();

    //构造访问标记矩阵
    vector<vector<bool>> visited;
    for (size_t idx = 0; idx < rows; idx++) {
        visited.push_back(vector<bool>(cols, false));
    }

    int wordIdx = 0;
    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            bool bexist = dfs(board, rows, cols, row, col, visited, word, wordIdx);
            if (bexist) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char** argv)
{
    vector<vector<char>> board;
    board.push_back(vector<char>{'a', 'b', 'c', 'e'});
    board.push_back(vector<char>{'s', 'f', 'c', 's'});
    board.push_back(vector<char>{'a', 'd', 'e', 'e'});

    {
        string word("abcced");
        bool bfind = exist(board, word);
        printf("find %s ret:%s\n", word.c_str(), bfind ? "true" : "false");
    }
    {
        string word("esceda");
        bool bfind = exist(board, word);
        printf("find %s ret:%s\n", word.c_str(), bfind ? "true" : "false");
    }
    {
        string word("escef");
        bool bfind = exist(board, word);
        printf("find %s ret:%s\n", word.c_str(), bfind ? "true" : "false");
    }
    getchar();
    return 0;
}
#endif // PATHINMATRIX
