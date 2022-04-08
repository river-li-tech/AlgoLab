#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
设计你的循环队列实现。 
循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。
它也被称为“环形缓冲器”。
*/
using namespace std;
class MyCircularQueue
{
public:
    MyCircularQueue(int k)
    {
        vec.resize(k);
        size = k;
        front = 0;
        count = 0;
    }

    bool enQueue(int value)
    {
        if (isFull()) return false;

        unsigned int rear = (front + count) % size;
        vec[rear] = value;
        count++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty()) return false;

        unsigned int val = vec[front];
        front = (front + 1) % size;
        count--;
        return true;
    }

    int Front()
    {
        if (isEmpty()) return -1;
        return vec[front];
    }

    int Rear()
    {
        if (isEmpty()) return -1;
        unsigned int rear = (front + count - 1) % size;
        return vec[rear];
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == size;
    }

private:
    vector<int> vec;
    unsigned int front;
    unsigned int rear;
    unsigned int size;
    unsigned int count;
};

#define CIRCLE_QUEUE
#ifdef CIRCLE_QUEUE
int main(int argc, char** argv)
{
    int k = 5;
    int value = 1;

    MyCircularQueue* circularQueue = new MyCircularQueue(3); 
    circularQueue->enQueue(7);
    circularQueue->deQueue();
    circularQueue->Front();
    circularQueue->deQueue();
    circularQueue->Front();
    circularQueue->Rear();
    circularQueue->enQueue(0);
    circularQueue->isFull(); 
    circularQueue->deQueue();
    circularQueue->Rear();
    circularQueue->enQueue(3);

    delete circularQueue;

    getchar();
    return 0;
}
#endif // CIRCLE_QUEUE
