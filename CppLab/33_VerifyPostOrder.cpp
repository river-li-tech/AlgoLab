#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
*/

//#define VERIFYPOSTORDER

#ifdef VERIFYPOSTORDER
using namespace std;

bool verifyPostorderPartial(vector<int>& postorder, int left, int right)
{
    if (left >= right) return true;
    if (left < 0 || right > postorder.size()) return false;

    int midVal = postorder[right];
    //找到中间分割序号
    size_t midIdx = left;
    for (; midIdx < right; midIdx++) {
        if (postorder[midIdx] > midVal) {
            break;
        }
    }
    //验证右边符合条件
    for (size_t idx = midIdx; idx < right; idx++) {
        if (postorder[idx] < midVal) {
            return false;
        }
    }
    //递归验证左半边
    if (midIdx > left) {
        if (!verifyPostorderPartial(postorder, left, midIdx - 1)) {
            return false;
        }
    }
    //递归验证右半边
    if (midIdx < right - 1) {
        if (!verifyPostorderPartial(postorder, midIdx, right - 1)) {
            return false;
        }
    }
    return true;
}

bool verifyPostorder(vector<int>& postorder)
{
    return verifyPostorderPartial(postorder, 0, postorder.size() - 1);
}

int main(int argc, char** argv)
{
    vector<int> vec{ 1,3,2,6,5 };
    vector<int> vec2{ 1,6,3,2,5 };
    bool bvalid = verifyPostorder(vec2);
    printf("verifyPostorder:%s\n", bvalid ? "true" : "false");

    getchar();

    return 0;
}
#endif // VERIFYPOSTORDER
