/* You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list. */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*p1=list1;
        ListNode*p2=list2;
        ListNode*dummy=new ListNode(-1);
        ListNode*p3=dummy;
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val<=p2->val)
            {
                p3->next=p1;
                p1=p1->next;
            }
            else
            {
                p3->next=p2;
                p2=p2->next;
            }
            p3=p3->next;
        }
        while(p1!=NULL)
        {
            p3->next=p1;
            p1=p1->next;
            p3=p3->next;
        }
        while(p2!=NULL)
        {
            p3->next=p2;
            p2=p2->next;
            p3=p3->next;
        }
        return dummy->next;
    }
};