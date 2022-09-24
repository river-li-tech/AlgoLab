/*
633. 平方数之和
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = (int)sqrt(c);
        long power = 0;
        while (left <= right)
        {
            power = left * left + right * right;
            if (power == c) return true;
            else if (power > c) right--;
            else left++;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    int c = 3;
    bool ret = sol.judgeSquareSum(c);
    cout << "judgeSquareSum:" << (ret? "true" : "false") << endl;
}
