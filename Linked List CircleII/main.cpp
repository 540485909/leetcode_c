#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n)return head;

        ListNode* pre=new ListNode(-1);
        pre->next=head;
        head=pre;
        ListNode* p=pre;
        ListNode* q,*r,*start;
        for(int i=0;i<m;i++)
         {
            pre=p;
            p=p->next;
         }
         q=p->next;
         start=p;

         for(int i=0;i<n-m&&q;i++)
         {
             r=q->next;
             q->next=p;
             p=q;
             q=r;

         }
         pre->next=p;
         start->next=q;
         pre=head;
         head=head->next;
         delete pre;
         return head;





    }
};
int main()
{
    ListNode *l1=new ListNode(1);
    ListNode *l2=new ListNode(2);
    ListNode *l3=new ListNode(3);
    ListNode *l4=new ListNode(4);
    ListNode *l5=new ListNode(5);
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;
    Solution s;
    l1=s.reverseBetween(l1,2,4);
    while(l1)
    {
        cout<<l1->val<<" ";
        l1=l1->next;
    }

    return 0;
}
