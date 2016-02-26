/**
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* even_list,*odd_list;
        ListNode *p,*q;
        odd_list=new ListNode(-1);
        even_list=new ListNode(-2);
        p=odd_list;
        q=even_list;
        while(head!=NULL){
           p->next=head;
            p=p->next;
            head=head->next;
           if(head!=NULL)
           {
                q->next=head;
                q=q->next;
                head=head->next;
           }else
		   {
			   q->next=NULL;
		   }
         
         
          
          
        }
        p->next=even_list->next;
        delete even_list;
		p=odd_list;
        odd_list=odd_list->next;
        delete p;
        return odd_list;
    }
};