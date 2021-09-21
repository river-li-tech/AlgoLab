#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>
#include <unordered_map>

/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
*/

#define FIRSTUNIQUECHAR

#ifdef FIRSTUNIQUECHAR
using namespace std;

char firstUniqChar(string s)
{
    unordered_map<char, bool> dic;
    vector<char> vec;

    for (auto c : s) {
        bool bfirst = dic.find(c) == dic.end();
        if (bfirst) {
            vec.push_back(c);
        }
        dic[c] = bfirst;
    }
    for (auto c : vec) {
        if (dic[c]) return c;
    }
    return ' ';
}

int main(int argc, char** argv)
{
    char c = firstUniqChar("abaccdeff"); 
    printf("firstUniqChar:%c\n", c);

    getchar();
    return 0;
}
#endif // FIRSTUNIQUECHAR

