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
        while(temp1!=NULL)
        {
            ListNode*temp2=headB;
            while(temp2!=NULL)
            {
                if(temp2==temp1)
                    return temp2;
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
       return NULL;
    }
};