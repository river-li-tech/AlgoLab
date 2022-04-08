#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
*/
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int sidx = -1, fidx = -1;
    int sum = 0;
    int len = gas.size();
    int cnt = len, idx = 0;
    while(cnt > 0 && idx != fidx) {
        sum += gas[idx] - cost[idx];
        if (sum < 0) {
            sum = 0;
            sidx = -1;
        } else if (sidx == -1) {
            sidx = idx;
            cnt = len;
            fidx = idx;
        }
        idx = (idx + 1) % len;
        cnt--;
    }
    return sidx;
}

//#define CAN_COMPLETE_CIRCUIT
#ifdef CAN_COMPLETE_CIRCUIT
int main(int argc, char** argv)
{
    //vector<int> gas{ 1, 2, 3, 4, 5 };
    //vector<int> cost{ 3, 4, 5, 1, 2 };
    vector<int> gas{ 5, 0, 9, 4, 3, 3, 9, 9, 1, 2};
    vector<int> cost{ 6, 7, 5, 9, 5, 8, 7, 1, 10, 5};
    //vector<int> gas{ 2, 3, 4};
    //vector<int> cost{ 3, 4, 3 };
    int ret = canCompleteCircuit(gas, cost);
    printf("jump:%d\n", ret);

    getchar();
    return 0;
}
#endif // CAN_COMPLETE_CIRCUIT
