/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// insert a new head node

#include<iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *left = dummy;
        ListNode *right = dummy;
        int count = 1;

        while (count <= n + 1)
        {
            right = right->next;
            count++;
        }

        while (right != NULL)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        return dummy->next;
    }
};