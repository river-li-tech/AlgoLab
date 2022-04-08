#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <deque>
#include <vector>
#include <queue>
#include <unordered_map>

/*
前 K 个高频元素
*/

using namespace std;

#define GUID_FORMAT
#ifdef GUID_FORMAT
int main(int argc, char** argv)
{
    char* p = "0x1a";
    int nValude = 0;
    sscanf(p, "%x", &nValude);
    printf("%d\r\n", nValude);
   
    getchar();
    return 0;
}
#endif // FIND_MIN_ARROW_SHOTS
