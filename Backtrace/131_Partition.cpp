#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <stack>
#include <vector>

/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
*/
using namespace std;

vector<string> path;
vector<vector<string>> result;

bool isPalindrome(string str)
{
    if (str.empty()) {
        return false;
    }

    int start = 0;
    int end = str.size() - 1;
    while (start < end) {
        if (str[start] != str[end]) return false;
        start++;
        end--;
    }
    return true;
}
void partitionBackTrace(const string &str, int startIdx)
{
    //终止条件
    if (startIdx >= str.size()) {
        result.push_back(path);
        return;
    }
    //递归
    for (int idx = startIdx; idx < str.size(); idx++) {
        string subStr = str.substr(startIdx, idx - startIdx + 1);
        if (isPalindrome(subStr)) {
            path.push_back(subStr);
        } else {
            continue;
        }
        partitionBackTrace(str, idx + 1);
        path.pop_back();
    }
}
vector<vector<string>> partition(string s)
{
    result.clear();
    path.clear();
    partitionBackTrace(s, 0);
    return result;
}

//#define PARTITION
#ifdef PARTITION
int main(int argc, char** argv)
{
    string str = "aab";
    vector<vector<string>> result = partition(str);
    for (auto vec : result) {
        for (auto item : vec) {
            printf("%s\t", item.c_str());
        }
        printf("\n");
    }

    getchar();
    return 0;
}
#endif // PARTITION
