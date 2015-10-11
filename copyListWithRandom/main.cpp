#include <iostream>

using namespace std;
  struct RandomListNode {
     int label;
    RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)return NULL;
        RandomListNode *p,*q,*newHead;
        p=head;
        while(p)
        {
            q=p->next;
            RandomListNode *Node=new RandomListNode(p->label);
            p->next=Node;
            Node->next=q;
            p=q;

        }
        p=head;

        newHead=p->next;
        while(p)
        {
            q=p->next;
            if(p->random)
            q->random=p->random->next;
            else q->random=NULL;
            p=q->next;

        }
        p=head;
        q=newHead;

         while(q->next)         {
            p->next = q->next;
             p= p->next;
             q->next = p->next;
            q = q->next;
         }
             p->next = NULL;
            q->next = NULL;




        return newHead;



    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
