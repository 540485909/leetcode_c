#include <iostream>

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}

};
class Solution {
public:
    ListNode* reverseList(ListNode *head){
        if(head==NULL)return head;
        if(head->next==NULL)return head;
        ListNode *p,*q,*r;
        p=head;
        q=head->next;
        p->next=NULL;
        while(q!=NULL){
            r=q->next;
            q->next=p;
            p=q;
            q=r;
        }
        return p;

    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)return true;

        ListNode *p,*q;
        p=head;
        int n=0;
        while(p!=NULL){
            p=p->next;
            n++;
        }
        p=head;
        for(int i=0;i<n/2-1;i++){
           p=p->next;
        }
        p=p->next;
        q=reverseList(p);
        p=head;
        while(p&&q){
            if(p->val==q->val){
                p=p->next;
                q=q->next;
            }else{
            return false;
            }

        }
        return true;



    }
};
int main()
{
    ListNode *l1=new ListNode(1);
     ListNode *l2=new ListNode(2);


    /*  ListNode *l3=new ListNode(5);

       ListNode *l4=new ListNode(4);

        ListNode *l5=new ListNode(5);

        ListNode *l6=new ListNode(4);

        ListNode *l7=new ListNode(3);

        ListNode *l8=new ListNode(2);

         ListNode *l9=new ListNode(1);
           l1->next=l2;l2->next=l3;l3->next=l4;l4->next=l5;l5->next=l6;l6->next=l7;l7->next=l8;l8->next=l9;*/
           l1->next=l2;
         Solution s;
        cout<< s.isPalindrome(l1);

    return 0;
}
