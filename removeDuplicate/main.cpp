#include <iostream>

using namespace std;
struct ListNode {
     int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode *p=head;
        ListNode *q;
        while(p)
        {
            q=p->next;
            while(q)
            {
                if(p->val==q->val)
               {
                   p->next=q->next;
                    delete q;
                   q=p->next;
               }
               else break;
            }
            p=p->next;

        }
        return head;
    }
    int removeDuplicates(int A[], int n) {
    if(n==1||n==0||n==2)return n;
    int i=2;
    int j=1;

    while(i<n)
    {
        if(A[i]==A[j]&&A[i]==A[j-1])
        {
           i++;

        }
        else
        {
            j++;

            A[j]=A[i];
             i++;

        }
        return j+1;
    }
   return j+1;
    }

};/*
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
          if(head==NULL||head->next==NULL)return head;
        ListNode *pre=new ListNode(-1);
        pre->next=head;
        head=pre;
        ListNode *p=pre->next;
        ListNode *q;
        bool flag;
        while(p)
        {
            q=p->next;
            flag=false;
            while(q)
            {

                if(p->val==q->val)
               {
                   flag=true;
                   p->next=q->next;
                    delete q;

                   q=p->next;
               }



               else break;
            }
             if(flag==true)
               {
                   pre->next=q;
                   delete p;
                   p=q;


               }
            if(flag==false)
            {
                pre=pre->next;
                p=pre->next;
            }

        }
        pre=head;
        head=head->next;
        delete pre;
        return head;
    }
};
int main()
{
    ListNode *head=new ListNode(1);
    head->next=new ListNode(1);
   // head->next->next=new ListNode(1);
    // head->next->next->next=new ListNode(0);
    Solution s;
    ListNode *result=s.deleteDuplicates(head);
    cout<<result<<endl;
  //  cout<<result->next<<endl;
    return 0;
}*/
