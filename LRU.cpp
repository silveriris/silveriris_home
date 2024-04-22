#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	int key, value;
    node* pre, * next;
    node() :key(-1), value(-1), pre(nullptr), next(nullptr) {}
    node(int k,int v):key(k),value(v),pre(nullptr),next(nullptr){}
    node(int k, int v,node* pre,node *next) :key(k), value(v), pre(pre), next(next) {}

    void push_front(int k,int v)
    {
        if (this->next)
        {
            this->next->pre = new node(k, v, this, this->next);
            this->next = this->next->pre;
        }
        else
        {
            this->next= new node(k, v, this, this);
            this->pre = this->next;
        }
    }
    void push_front(node* n)
    {
        n->next->pre = n->pre;
        n->pre->next = n->next;
        this->push_front(n->key, n->value);
        delete n;
    }
    void pop_back()
    {
        node* p = this->pre;
        this->pre->pre->next=this;
        this->pre = this->pre->pre;
        delete p;
    }
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (h[key]==nullptr)
        {
            return -1;
        }
        else
        {
            if (n->next != h[key])
            {
                n->push_front(h[key]);
                h[key] = n->next;
            }
            return h[key]->value;
        }
    }

    void put(int key, int value)
    {
        if (h[key]!=nullptr)
        {
            h[key]->value = value;
            n->push_front(h[key]);
            h[key] = n->next;
            return;
        }
        if (cap>0)
        {
            n->push_front(key, value);
            h[key] = n->next;
            cap--;

            return;
        }
        if(cap==0)
        {
            h[n->pre->key] = nullptr;
            n->pop_back();
            n->push_front(key, value);
            h[key] = n->next;

            return;
        }
        
    }
private:
    int cap;
    node *n = new node();
    node* h[10001] = { nullptr };
};
int main()
{
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(2, 1); // 缓存是 {1=1}
    lRUCache->put(1, 1); // 缓存是 {1=1, 2=2}
    lRUCache->put(2, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache->put(4, 1); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache->get(1);    // 返回 -1 (未找到)
    cout << lRUCache->get(2);    // 返回 3

	return 0;
}