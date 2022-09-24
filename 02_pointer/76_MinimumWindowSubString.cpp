/*
76. 最小覆盖子串
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (int idx = 0; idx < t.length(); idx++)
        {
            map[t[idx]]++;
        }
        
        int min_left = 0, min_len = s.length() + 1;
        int left, cnt;
        left = cnt = 0;
        for (int right = 0; right < s.length(); right++)
        {
            char ch = s[right];
            if (map.find(ch) != map.end()) {
                if (--map[ch] >= 0) {
                    cnt++;  
                }
                while (cnt == t.length()) {
                    if ((right - left + 1) < min_len) {
                        min_len = right - left + 1;
                        min_left = left;
                    }
                    char chleft = s[left];
                    if (map.find(chleft) != map.end() && ++map[chleft] > 0) {
                        cnt--;
                    }
                    left++;
                }
            }
        }
        return min_len > s.length() ? "" : s.substr(min_left, min_len);
    }
};

int main()
{
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ret = sol.minWindow(s, t);
    cout << "minWindow:" << ret << endl;
}
