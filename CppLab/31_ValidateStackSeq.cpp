#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
*/

#define VALIDATESTACKSEQ

#ifdef VALIDATESTACKSEQ
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
    if (pushed.size() == 0 && popped.size() == 0) return true;
    if (pushed.size() == 0 || popped.size() == 0) return false;

    stack<int> tstack;
    int pidx = 0;
    for (size_t idx = 0; idx < pushed.size(); idx++) {
        tstack.push(pushed[idx]);
        while (pidx < popped.size() && tstack.size() > 0 && popped[pidx] == tstack.top()) {
            tstack.pop();
            pidx++;
        }
    }
    return tstack.empty();
}

int main(int argc, char** argv)
{
    vector<int> pushd{ 1, 2, 3, 4, 5, 6 };
    //vector<int> popped{ 4, 6, 5, 3, 2, 1 };
    vector<int> popped{ 4, 6, 2, 3, 5, 3, 1 };
    bool bvalid = validateStackSequences(pushd, popped);
    printf("ValidateStackSeq:%s\n", bvalid ? "true" : "false");
   
    getchar();
    return 0;
}
#endif // VALIDATESTACKSEQ
