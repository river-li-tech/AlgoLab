/*
135. 分发糖果
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for(int idx = 1; idx < ratings.size(); idx++) {
            if (ratings[idx] > ratings[idx - 1]) {
                candies[idx] = candies[idx - 1] + 1;
            }
        }
        for(int idx = ratings.size() - 2; idx >= 0; idx--) {
            if (ratings[idx] > ratings[idx + 1]) {
                candies[idx] = max(candies[idx], candies[idx + 1] + 1);
            }
        }

        int sum = 0;
        for(int cdy : candies) {
            sum += cdy;
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> ratings{1, 2, 2};
    int ret = sol.candy(ratings);
    cout << "candy: " << ret << endl;
    return 0; 
}
