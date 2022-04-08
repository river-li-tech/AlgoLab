#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
·Ö·¢±ý¸É
*/
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int gidx = 0;
    int ret = 0;
    for (int sidx = 0; sidx < s.size(); sidx++) {
        if (g[gidx] <= s[sidx] && gidx < g.size()) {
            gidx++;
            ret++;
        }
    }
    return ret;
}

//#define FIND_CONTENT_CHILDREN
#ifdef FIND_CONTENT_CHILDREN
int main(int argc, char** argv)
{
    vector<int> g{ 1, 2, 7, 10 };
    vector<int> s{1, 3, 5, 9};
    int ret = findContentChildren(g, s);
    printf("findContentChildren:%d\n", ret);

    getchar();
    return 0;
}
#endif // FIND_CONTENT_CHILDREN
