/*
406. 根据身高重建队列
假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [&](vector<int>& left, vector<int>& right) {
            if (left[0] != right[0]) {
                return left[0] > right[0];
            }
            return left[1] < right[1];
        };
        sort(people.begin(), people.end(), cmp);
        
        vector<vector<int>> ans;
        for (vector<int>& p : people)
        {
            ans.insert(ans.begin() + p[1], p);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> people{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> ret = sol.reconstructQueue(people);
    for_each(ret.begin(), ret.end(), [&](vector<int>& vec){
        cout << vec[0] << "," << vec[1] << endl;
    });
    return 0; 
}
