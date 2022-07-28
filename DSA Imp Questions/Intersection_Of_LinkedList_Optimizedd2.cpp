//Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*temp1=headA;
        ListNode*temp2=headB;
        while(temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==NULL && temp2==NULL)
                return NULL;
            if(temp1==NULL)
                temp1=headB;
            if(temp2==NULL)
                temp2=headA;
        }
            return temp1;
    }
};