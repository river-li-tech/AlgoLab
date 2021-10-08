#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <stack>
#include <vector>

/*
计算逆波兰表达式
*/

using namespace std;
int evalRPN(vector<string>& tokens)
{
    stack<int> stk;
    for (auto token : tokens) {
        if (token == "+" || token == "-" || token == "/" || token == "*") {
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
            stk.pop();
            if (token == "+") stk.push(num2 + num1);
            if (token == "-") stk.push(num2 - num1);
            if (token == "*") stk.push(num2 * num1);
            if (token == "/") stk.push(num2 / num1);
        } else {
            stk.push(stoi(token));
        }
    }
    int ret = stk.top();
    stk.pop();
    return ret;
}

//#define EVAL_RPN
#ifdef EVAL_RPN
int main(int argc, char** argv)
{
    vector<string> str{ "2","1","+","3","*" };
    int ret = evalRPN(str);
    printf("evalRPN：%d\n", ret);

    getchar();
    return 0;
}
#endif // EVAL_RPN
