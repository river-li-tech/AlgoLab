/*
524. 通过删除字母匹配到字典里最长单词
给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for (int idx = 0; idx < dictionary.size(); idx++)
        {
            string str = dictionary[idx];
            if (IsMatch(s, str)) {
                if (str.length() > ans.length()
                    || str.length() == ans.length() && str < ans) {
                    ans = str;
                }
            }
        }
        return ans;
    }

    bool IsMatch(string left, string right)
    {
        int lp = 0, rp = 0;
        while(lp < left.length() && rp < right.length()) {
            if (left[lp] == right[rp]) {
                rp++;
            }
            lp++;
        }
        if (rp == right.length()) return true;
        return false;
    }
};

int main()
{
    Solution sol;
    string s = "abpcplea";
    vector<string> dictionary{"ale","apple","monkey","plea"};
    string ret = sol.findLongestWord(s, dictionary);
    cout << "findLogestWord:" << ret << endl;
}
