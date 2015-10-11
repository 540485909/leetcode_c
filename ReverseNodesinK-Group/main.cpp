#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};

};
struct Node
{
    ListNode *beg;
    ListNode *tail;
    Node(){};
    Node(ListNode *b,ListNode *t):beg(b),tail(t){};
};
class Solution {
public:
    Node rever(ListNode *beg,ListNode *tail)
    {
        ListNode *pPre=NULL;
        ListNode *p=beg;
        while(p!=tail)
        {
            ListNode *pNext=p->next;
            p->next=pPre;
            pPre=p;
            p=pNext;
        }
        p->next=pPre;
        return Node(tail,beg);
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL)return head;
        ListNode *pPre=NULL;
        ListNode *p=head;
        while(p)
        {
            ListNode *q=p;
            for(int i=0;i<k-1;i++)
            {
                q=q->next;
                if(q==NULL)return head;
            }
            ListNode *qNext=q->next;
            Node ret=rever(p,q);
            if(pPre)
                pPre->next=ret.beg;
            else head=ret.beg;
            ret.tail->next=qNext;
            pPre=ret.tail;
            p=qNext;
        }

    }

};
int main()
{

    return 0;
}
