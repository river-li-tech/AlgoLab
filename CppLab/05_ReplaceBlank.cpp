#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

//#define REPLACEBLANK

#ifdef REPLACEBLANK
using namespace std;
string ReplaceBlank(string s)
{
    int originCnt = s.size();

    int blankCnt = 0;
    for (int idx = 0; idx < s.size(); idx++) {
        if (s[idx] == ' ') {
            blankCnt++;
        }
    }

    if (blankCnt == 0) {
        return s;
    }

    string newStr(originCnt + blankCnt * 2, ' ');
    int newIdx = newStr.size() - 1;
    for (int idx = originCnt - 1; idx >= 0; idx--) {
        if (s[idx] != ' ') {
            newStr[newIdx--] = s[idx];
        } else {
            newStr[newIdx--] = '0';
            newStr[newIdx--] = '2';
            newStr[newIdx--] = '%';
        }
    }
    return newStr;
}

int main(int argc, char** argv)
{
    string str = "We are   happy.";
    string newStr = ReplaceBlank(str);
    printf("ReplaceBlank:%s ret:%s\n", str.c_str(), newStr.c_str());
    getchar();

    return 0;
}
#endif // REPLACEBLANK
