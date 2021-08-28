#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*/

//#define CUTTINGROPE

#ifdef CUTTINGROPE
using namespace std;

int cuttingRope(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 2;

    int* products = new int[n + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    for (int len = 4; len <= n; len++) {
        max = 0;
        for (int hlen = 1; hlen <= len / 2; hlen++) {
            int product = products[hlen] * products[len - hlen];
            if (max < product) {
                max = product;
            }
        }
        products[len] = max;
    }

    max = products[n];
    delete[] products;
    return max;
}

int main(int argc, char** argv)
{
    printf("len:%d max:%d\n", 5, cuttingRope(5));
    printf("len:%d max:%d\n", 10, cuttingRope(10));
    printf("len:%d max:%d\n", 15, cuttingRope(15));
    printf("len:%d max:%d\n", 100, cuttingRope(100));

    getchar();
    return 0;
}
#endif // CUTTINGROPE
