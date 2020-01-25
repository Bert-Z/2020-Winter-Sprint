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

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head != NULL && head->val == val)
            head = head->next;

        if (head == NULL)
            return NULL;

        ListNode *ahead = head;
        ListNode *tail = head->next;
        while (tail != NULL)
        {
            if (tail->val != val)
                ahead = ahead->next;
            else
                ahead->next = tail->next;

            tail = tail->next;
        }

        return head;
    }
};