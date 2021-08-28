
#include <cstdio>
#include <cstdlib>
#include <vector>

//#define GETDUPLICATION

#ifdef GETDUPLICATION
int GetCount(std::vector<int>& vec, int start, int end);

int GetDuplication(std::vector<int>& vec)
{
    if (vec.size() == 0) {
        return -1;
    }

    //容器内10个数字，在1-9之间（有9个）
    int start = 1;
    int end = vec.size() - 1;
    //对9个数字使用二分法
    while (start <= end) {
        int middle = (end - start) / 2 + start;
        int count = GetCount(vec, start, middle);//计算出现次数

        if (start == end) {
            if (count > 1) {
                return start;
            } else {
                return -1;
            }
        }
        //调整二分法区间
        if (count > (middle - start + 1)) {
            end = middle;
        } else {
            start = middle + 1;
        }
    }
    return -1;
}

int GetCount(std::vector<int>& vec, int start, int end)
{
    if (start >= vec.size() || end >= vec.size()) {
        return 0;
    }
    int count = 0;
    for (int idx = 0; idx < vec.size(); idx++) {
        if (vec[idx] >= start && vec[idx] <= end) {
            count++;
        }
    }
    return count;
}

int main(int argc, char** argv)
{
    std::vector<int> vec{1, 2, 5, 6, 4, 8, 9, 3, 4, 8};
    int dup = GetDuplication(vec);
    printf("GetDuplication:%d\n", dup);
    getchar();

    return 0;
}
#endif // GETDUPLICATION
