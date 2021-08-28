#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

/*
编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。
*/

#define HAMMINGWEIGHT

#ifdef HAMMINGWEIGHT
using namespace std;

int hammingWeight(uint32_t n)
{
    int count = 0;
    uint32_t flag = 1;
    while (flag) {
        if (flag & n) {
            count++;
        }
        flag = flag << 1;
    }
    return count;
}

int hammingWeight2(uint32_t n)
{
    int count = 0;
    while (n) {
        n = (n - 1) & n;
        count++;
    }
    return count;
}

int main(int argc, char** argv)
{
    printf("num:%d weiht:%d\n", 10, hammingWeight(10));
    printf("num:%d weiht:%d\n", 10, hammingWeight2(10));
    printf("num:%d weiht:%d\n", 256, hammingWeight(256));
    printf("num:%d weiht:%d\n", 256, hammingWeight2(256));

    getchar();
    return 0;
}
#endif // HAMMINGWEIGHT
