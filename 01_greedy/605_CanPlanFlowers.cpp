/*
605. 种花问题
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给你一个整数数组  flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false。
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() < n) return false;
        if (n <= 0) return true;

        for (int idx = 0; idx < flowerbed.size(); idx++)
        {
            if (flowerbed[idx] == 0) {
                bool left = (idx - 1) < 0 || (idx - 1) >= 0 && flowerbed[idx - 1] == 0;
                bool right = (idx + 1) >= flowerbed.size() || (idx + 1) < flowerbed.size() && flowerbed[idx + 1] == 0;
                if (left && right) {
                    flowerbed[idx] = 1;
                    n--;
                    if (n <= 0) return true;
                }
            }
        }
        if (n == 0) return true;
        else return false;
    }
};

int main()
{
    Solution sol;
    vector<int> flowerbed{1,0,0,0,0,1};
    int n = 2;
    bool ret = sol.canPlaceFlowers(flowerbed, n);
    cout << "canPlaceFlowers: " << (ret ? "true" : "false") << endl;
}
