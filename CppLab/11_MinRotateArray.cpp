#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//#define MINROTATEARRAY

#ifdef MINROTATEARRAY
using namespace std;

int minInOrder(vector<int>& numbers, int start, int end)
{
    int min = INT32_MAX;
    for (int idx = start; idx <= end; idx++) {
        if (numbers[idx] < min) {
            min = numbers[idx];
        }
    }
    return min;
}

int minArray(vector<int>& numbers)
{
    if (numbers.size() == 0) return -1;
    if (numbers.size() == 1) return numbers[0];

    int left = 0;
    int right = numbers.size() - 1;
    int middle = left;
    //更严格的条件：左边不能超过右边
    while (numbers[left] >= numbers[right]) {
        if ((right - left) == 1) {  //相邻
            middle = right;
            break;
        }
        middle = (right - left) / 2 + left;

        //middle与left/right完全相同，无法判定，使用顺序遍历
        if (numbers[left] == numbers[right] && numbers[left] == numbers[middle]) {
            return minInOrder(numbers, left, right);
        }
        //二分法
        if (numbers[middle] >= numbers[left]) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return numbers[middle];
}

int main(int argc, char** argv)
{
    vector<int> arr1{ 3, 4, 5, 1, 2 };
    vector<int> arr2{ 2, 2, 2, 0, 1 };
    vector<int> arr3{ 1, 1, 1, 0, 1 };
    vector<int> arr4{ 1, 0, 1, 1, 1 };
    vector<int> arr5{1, 2, 3, 4, 5};

    printf("arr1 min:%d\n", minArray(arr1));
    printf("arr2 min:%d\n", minArray(arr2));
    printf("arr3 min:%d\n", minArray(arr3));
    printf("arr4 min:%d\n", minArray(arr4));
    printf("arr5 min:%d\n", minArray(arr5));

    getchar();

    return 0;
}
#endif // MINROTATEARRAY
