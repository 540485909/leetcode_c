#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseListRecursion(ListNode *prev,ListNode* head){
        if(head==NULL) return head;
        ListNode *next=head->next;
        head->next=prev;
        prev=head;
        reverseListRecursion(prev,next);
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        head=reverseListRecursion(NULL,head);
        return head;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
