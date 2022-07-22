//Given the head of a linked list, remove the nth node from the end of the list and return its head.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return head;
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        ListNode*previous=head;
        if(n==count)
        {
            head=previous->next;
            delete previous;
            return head;
        }
        for(int i=0;i<count-n-1;i++)
            previous=previous->next;
        ListNode*current=previous->next;
        previous->next=current->next;
        delete current;
        return head;
    }
};