#include <iostream>
#include <map>
using namespace std;
struct node
{
    int key;
    int value;
    node *next;
    node *pre;
    node(int a,int b):key(a),value(b),next(NULL),pre(NULL){}
};
class LRUCache{
    node *head;
    node *tail;
    int siz;
    int capacity;
    map<int,node*> mp;
public:
    LRUCache(int capacity) {
        if(capacity<1)return ;
        this->capacity=capacity;
        siz=0;
        head=new node(0,0);
        tail=new node(0,0);
        head->pre=tail;
        tail->next=head;
        mp.clear();
        }

    int get(int key) {
        map<int,node*>::iterator it=mp.find(key);
        if(it!=mp.end())
        {
            node *cur=(*it).second;
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            putToHead(cur);
            return cur->value;

        }
        else return -1;

    }

    void set(int key, int value) {
        if(capacity<1)return ;
        map<int,node*>::iterator it=mp.find(key);
        if(it!=mp.end())
        {
            node *cur=(*it).second;
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            putToHead(cur);


        }
        else
            {
                node *newNode=new node(key,value);
                 putToHead(newNode);
                 mp[key]=newNode;
                if(siz<capacity)siz++;
                else
                    {
                         node* deltmp = tail->pre;
                tail->pre = deltmp->pre;
                deltmp->pre->next = tail;
                it = mp.find(deltmp->key);
                mp.erase(it);
                delete deltmp;

                }


            }
    }
    void putToHead(node* cur)
    {
        cur->next = head->next;
        cur->pre = head;
        cur->next->pre = cur;
        head->next = cur;
    }


};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
