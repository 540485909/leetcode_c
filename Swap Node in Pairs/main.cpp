#include <iostream>

using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode *p,*q,*r;
        p=head;
        q=head->next;
        if(q==NULL)return head;
        r=q->next;
        q->next=p;
        p->next=swapPairs(r);



        return q;

    }
};
int main()
{
    ListNode *n1,*n2,*n3,*n4;
    n1=new ListNode(1);
    n2=new ListNode(2);
    n3=new ListNode(3);
    n4=new ListNode(4);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    Solution s;
    ListNode *head=s.swapPairs(n1);
   while(head)
   {
       cout<<head->val;
       head=head->next;
   }

}
