#include <iostream>
#include <cmath>
using namespace std;
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    int calucateLength(ListNode *head)
    {
        int len=0;
        ListNode *p=head;
        while(p)
        {
            p=p->next;
            len++;
        }
        return len;

    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)return NULL;
        ListNode *p=headA;
        ListNode *q=headB;
        int lenA=calucateLength(headA);
        int lenB=calucateLength(headB);
        int a=lenA-lenB;
        if(a>=0)
        {
            for(int i=0;i<a;i++)
            p=p->next;
            while(p&&q)
            {
                if(p==q)return q;
                else
                {
                    p=p->next;
                    q=q->next;
                }
            }

        }
        else
        {
            for(int i=0;i<abs(a);i++)
            q=q->next;
            while(p&&q)
            {
                 if(p==q)return q;
                else
                {
                    p=p->next;
                    q=q->next;
                }
            }

        }
        return NULL;

    }
};
int main()
{
    Solution s;
    ListNode *headA=new ListNode(1);
    ListNode *headB=headA;
    cout<<s.getIntersectionNode(headA,headB)->val;
    return 0;
}
