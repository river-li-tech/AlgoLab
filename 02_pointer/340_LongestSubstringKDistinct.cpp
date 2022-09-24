/*
340. 至多包含 K 个不同字符的最长子串
给你一个字符串 s 和一个整数 k ，请你找出 至多 包含 k 个 不同 字符的最长子串，并返回该子串的长度。
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.length() <= k) return s.length();

        unordered_map<char, int> map;
        int left, right, cnt, len;
        left = cnt = len = 0;
        for (int right = 0; right < s.length(); right++)
        {
            char ch = s[right];
            if (map.find(ch) != map.end()) {
                map[ch]++;
            } else {
                map[ch]++;
                cnt++;
            }
            if (cnt <= k) {
                if (right - left + 1 > len) {
                    len = right - left + 1;
                }
            } 
            while(cnt > k) {
                char lch = s[left];
                if (--map[lch] == 0) {
                    map.erase(lch);
                    cnt--;
                }
                left++;   
            }
        }
        return len;
    }
};

int main()
{
    Solution sol;
    string s = "nfhiexxjrtvpfhkrxcutexxcodfioburrtjefrgwrnqtyzelvtpvwdvvpsbudwtiryqzzy";
    int k = 25;
    int ret = sol.lengthOfLongestSubstringKDistinct(s, k);
    cout << "lengthOfLongestSubstringKDistinct:" << ret << endl;
}
