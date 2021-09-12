#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>

/*
输入一个字符串，打印出该字符串中字符的所有排列。
*/

//#define PERMUTATION

#ifdef PERMUTATION
using namespace std;

//下一序列算法
bool permutationNext(string& s)
{
    int minIdx = s.size() - 2;
    //从后往前找到最小值
    while (minIdx >= 0 && s[minIdx] >= s[minIdx + 1]) {
        minIdx--;
    }
    if (minIdx < 0) return false;
    //从后往前找到相对大值(相对以上最小值）
    int maxIdx = s.size() - 1;
    while (maxIdx >= 0 && s[minIdx] >= s[maxIdx]) {
        maxIdx--;
    }
    //交换
    swap(s[minIdx], s[maxIdx]);
    //尾部从小到达排序
    sort(s.begin() + minIdx + 1, s.end());
    return true;
}
vector<string> permutation(string s)
{
    vector<string> vec;
    if (s.empty()) return vec;
    if (s.size() == 1) {
        vec.push_back(s);
        return vec;
    }

    sort(s.begin(), s.end());
    do {
        vec.push_back(s);
    } while (permutationNext(s));
    return vec;
}

//回溯法
vector<bool> _vis;
vector<string> _ret;
void backtrace(const string& str, int bidx, string& perm)
{
    if (bidx == str.size()) {
        _ret.push_back(perm);
    }

    for (size_t idx = 0; idx < str.size(); idx++) {
        if (_vis[idx] || (idx > 0 && !_vis[idx - 1] && str[idx] == str[idx - 1])) {
            continue;
        }
        _vis[idx] = true;
        perm.push_back(str[idx]);
        backtrace(str, bidx + 1, perm);
        perm.pop_back();
        _vis[idx] = false;
    }
}
vector<string> permutation2(string s)
{
    if (s.empty()) return _ret;
    if (s.size() == 1) {
        _ret.push_back(s);
        return _ret;
    }

    int size = s.size();
    _vis.resize(size);
    sort(s.begin(), s.end());

    string perm;
    backtrace(s, 0, perm);
    return _ret;
}

int main(int argc, char** argv)
{
    string str = "445";
    {
        printf("permutation1:\n");
        vector<string> vec = permutation(str);
        for (size_t idx = 0; idx < vec.size(); idx++) {
            printf("%s\n", vec[idx].c_str());
        }
    }
    {
        printf("permutation2:\n");
        vector<string> vec = permutation2(str);
        for (size_t idx = 0; idx < vec.size(); idx++) {
            printf("%s\n", vec[idx].c_str());
        }
    }

    getchar();
    return 0;
}
#endif // PERMUTATION
