#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

class Routine
{
public:
    virtual void Handle() { printf("Routine:Handle\n"); };
};

class SubRoutine : public Routine
{
};

class Container: public SubRoutine
{
public:
    void Handle() { printf("Container:Handle\n"); };
};


int main(int argc, char** argv)
{
    Container* ptr = new Container();
    ptr->Handle();

    delete ptr;
    getchar();
    return 0;
}
