#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
Ï£¶ûÅÅÐò
*/
using namespace std;

void ShellSort(vector<int>& arr)
{
    if (arr.size() <= 1) return;

}

//#define SHELL_SORT
#ifdef SHELL_SORT
int main(int argc, char** argv)
{
    //vector<int> arr;
    //srand((unsigned)time(NULL));
    //for (size_t idx = 10; idx > 0; idx--) {
    //    arr.push_back(idx);
    //}
    vector<int> arr{2, 4, 1, 0, 7, 3, 6, 1};
    clock_t start = clock();
    ShellSort(arr);
    clock_t end = clock();
    printf("ShellSort Elapsed:%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (auto num : arr) {
        printf("%d\t", num);
    }
    //printf("\n");

    getchar();
    return 0;
}
#endif // SHELL_SORT
