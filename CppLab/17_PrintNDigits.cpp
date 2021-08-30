#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
*/

//#define PRINTNDIGITS

#ifdef PRINTNDIGITS
using namespace std;

vector<int> printNumbers(int n)
{
    if (n <= 0) {
        return vector<int>();
    }
    int maxNum = 0;
    if (n >= 8) {
        maxNum = INT32_MAX;
    } else {
        char *buffer = new char[n + 1];
        memset(buffer, '\0', n + 1);
        for (size_t idx = 0; idx < n; idx++) {
            buffer[idx] = '9';
        }
        maxNum = atoi(buffer);
    }

    vector<int> numbers;
    for (int idx = 1; idx <= maxNum; idx++) {
        numbers.push_back(idx);
    }
    return numbers;
}

int main(int argc, char** argv)
{
    {
        vector<int> numbers = printNumbers(2);
        for (int idx = 0; idx < numbers.size(); idx++) {
            printf("%d\t", numbers[idx]);
        }
        printf("\n");
    }

    /*{
        vector<int> numbers = printNumbers(33);
        for (int idx = 0; idx < numbers.size(); idx++) {
            printf("%d\t", numbers[idx]);
        }
        printf("\n");
    }*/

    getchar();
    return 0;
}
#endif // PRINTNDIGITS
