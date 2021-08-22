#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

/*
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）
*/

//#define FIBONACCI

#ifdef FIBONACCI
using namespace std;

int Fibonacci(int n)
{
    int result[2] = { 0, 1 };
    if (n < 2) return result[n];

    int left = 0;
    int right = 1;
    int ret = 0;
    for (int idx = 2; idx <= n; idx++) {
        ret = (left + right) % 1000000007;
        left = right;
        right = ret;
    }
    return ret;
}

//一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
int FrogLip(int n)
{
    if (n < 0) return 0;
    
    int result[3] = { 1, 1, 2};
    if (n <= 2) return result[n];

    int left = 1;
    int right = 2;
    int ret = 0;
    for (int idx = 3; idx <= n; idx++) {
        ret = (left + right) % 1000000007;
        left = right;
        right = ret;
    }
    return ret;
}

//如果青蛙可以一次跳 1 级，也可以一次跳 2 级，一次跳 3 级，…，一次跳 nn 级。问要跳上第 nn 级台阶有多少种跳法？
 int FrogLip2(int n)
{
    if (n < 0) return 0;
    int result[2] = { 1, 1};
    if (n < 2) return result[n];

    return (int)powl(2, (long double)n - 1) % 100000007;
}

int main(int argc, char** argv)
{
    for (int idx = 0; idx <= 45; idx++) {
        printf("%d->%d\n", idx, Fibonacci(idx));
    }

    printf("Frog lip...\n");
    for (int idx = 0; idx <= 45; idx++) {
        printf("%d->%d\n", idx, FrogLip(idx));
    }

    printf("Frog lip2...\n");
    for (int idx = 0; idx <= 45; idx++) {
        printf("%d->%d\n", idx, FrogLip2(idx));
    }
    getchar();

    return 0;
}
#endif // FIBONACCI
