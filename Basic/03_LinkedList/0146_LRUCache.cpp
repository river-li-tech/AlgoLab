#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <unordered_map>

/*
146. LRU 缓存
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/
using namespace std;
class CacheNode
{
public:
    CacheNode() : val(-1), next(nullptr), prev(nullptr) {}
    CacheNode(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
public:
    int key;
    int val;
    CacheNode* next;
    CacheNode* prev;
};

//双向链表
class Deque
{
public:
    Deque() : _size(0)
    {
        //虚头尾节点
        head = new CacheNode();
        tail = new CacheNode();
        head->next = tail;
        tail->prev = head;
    }

    ~Deque()
    {
        delete head;
        delete tail;
        _size = 0;
    }
    //添加到头
    void addToHead(CacheNode* node)
    {
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
        _size++;
    }
    //添加到尾
    void addToTail(CacheNode* node)
    {
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        node->next = tail;
        _size++;
    }
    //获取尾节点
    CacheNode* getTail()
    {
        if (_size == 0) return nullptr;
        return tail->prev;
    }
    //删除节点（不删除）
    void remove(CacheNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
        _size--;
    }

    int size()
    {
        return _size;
    }

private:
    CacheNode* head;
    CacheNode* tail;
    int _size;
};

class LRUCache
{
public:
    LRUCache(int capacity) : cap(capacity)
    {
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        //移动到头部
        CacheNode* node = mp[key];
        dq.remove(node);
        dq.addToHead(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end()) {
            CacheNode* node = new CacheNode(key, value);
            //超出则删除尾部
            if (dq.size() >= cap) {
                CacheNode* tail = dq.getTail();
                mp.erase(tail->key);
                dq.remove(tail);
                delete tail;
                tail = nullptr;
            }
            //添加到头部（新数据放在头部）
            mp.insert({ key, node });
            dq.addToHead(node);
        } else {
            //更新数值，同时放入头部
            CacheNode* node = mp[key];
            node->val = value;
            dq.remove(node);
            dq.addToHead(node);
        }
    }

private:
    unordered_map<int, CacheNode*> mp;  //建立索引
    Deque dq;                           //维护顺序，存储
    int cap;                            //容量
};

//#define LRU_CACHE
#ifdef LRU_CACHE
int main(int argc, char* argv)
{
    int capacity = 10;
    LRUCache* obj = new LRUCache(capacity);
    //int param_1 = obj->get(1);
    //obj->put(key, value);

    getchar();
    return 0;
}
#endif // LRU_CACHE
