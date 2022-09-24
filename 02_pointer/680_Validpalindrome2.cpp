/*
680. 验证回文串 II
给你一个字符串 s，最多 可以从中删除一个字符。

请你判断 s 是否能成为回文字符串：如果能，返回 true ；否则，返回 false
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left <= right)
        {
            if (s[left] != s[right]) {
                return IsPalindrome(s.substr(left + 1, right - left)) || 
                        IsPalindrome(s.substr(left, right - left));
            }
            left++;
            right--;
        }
        return true;
    }

    bool IsPalindrome(string s)
    {
        int left = 0, right = s.length() - 1;
        while (left <= right)
        {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "abca";
    bool ret = sol.validPalindrome(s);
    cout << "validPalindrome:" << (ret ? "true" : "false") << endl;
}
