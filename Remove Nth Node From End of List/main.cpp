#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL)return head;
        ListNode *nHead=new ListNode(-1);
        nHead->next=head;
        head=nHead;
        ListNode *p,*q,*pre;
        p=head;
        q=head;
        for(int i=0;i<n;i++)
            q=q->next;
        while(q)
        {
            pre=p;
            p=p->next;
            q=q->next;

        }
        p=pre->next;
        pre->next=p->next;
        delete p;
        head=head->next;
        delete nHead;
        return head;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
