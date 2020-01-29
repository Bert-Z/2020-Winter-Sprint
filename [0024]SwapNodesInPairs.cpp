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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode *newd=dummy;
        ListNode *fir=dummy->next;
        ListNode *sec=dummy->next->next;
        ListNode *last=dummy->next->next->next;
        
        while(sec!=NULL){ 
            helper(newd,fir,sec,last);
            
            if(last==NULL||last->next==NULL)
                break;
            
            newd=fir;
            fir=last;
            sec=last->next;
            last=last->next->next;
        }
        
        return dummy->next;
    }
    
private:
    void helper(ListNode *newd, ListNode *fir, ListNode *sec, ListNode *last){
        newd->next=fir->next;
        fir->next=sec->next;
        sec->next=fir;
    }
    
};