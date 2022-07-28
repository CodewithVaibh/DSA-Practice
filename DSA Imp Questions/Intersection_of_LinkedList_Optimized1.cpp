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
        int c1,c2;
        c1=c2=0;
        while(temp1!=NULL || temp2!=NULL)
        {
            if(temp1!=NULL)
            {
                temp1=temp1->next;
                c1++;
            }
            if(temp2!=NULL)
            {
                temp2=temp2->next;
                c2++;
            }
        }
        temp1=headA;
        temp2=headB;
        int c=abs(c1-c2);
        if(c1>=c2)
        {
            int i=0;
            while(i!=c)
            {
                temp1=temp1->next;
                    i++;
            }
        }
        else
        {
            int i=0;
            while(i!=c)
            {
                temp2=temp2->next;
                    i++;
            }
        }
        while(temp1!=temp2 && temp1!=NULL)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1==NULL)
            return NULL;
        else
            return temp1;
    }
};