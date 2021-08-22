#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//#define QUEUEBYSTACK

#ifdef QUEUEBYSTACK
using namespace std;

class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        stack1.push(value);
    }

    int deleteHead()
    {
        if (stack2.size() == 0) {
            while (stack1.size() > 0) {
                int val = stack1.top();
                stack1.pop();
                stack2.push(val);
            }
        }
        if (stack2.size() > 0) {
            int val = stack2.top();
            stack2.pop();
            return val;
        } else {
            return -1;
        }
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, char** argv)
{
    CQueue queue;
    queue.appendTail(1);
    queue.appendTail(2);
    queue.appendTail(3);
    printf("%d\n", queue.deleteHead());
    queue.appendTail(4);
    printf("%d\n", queue.deleteHead());
    printf("%d\n", queue.deleteHead());
    printf("%d\n", queue.deleteHead());

    queue.appendTail(1);

    getchar();

    return 0;
}
#endif // QUEUEBYSTACK
