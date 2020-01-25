/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur=head;
        if(head==NULL)
            return NULL;
        
        ListNode* n=cur->next;
        if(n==NULL)
            return head;
        
        ListNode* nn=cur->next->next;
        cur->next=NULL;
        while(cur!=NULL&&n!=NULL&&nn!=NULL){ 
            n->next=cur;
            cur=n;
            n=nn;
            nn=nn->next;
        }
        n->next=cur;
        return n;
    }
};