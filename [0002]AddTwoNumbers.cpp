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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *root = new ListNode(0);
        int up = 0;

        ListNode *cur = root;

        while (l1 != NULL && l2 != NULL)
        {
            cur->next = new ListNode(helper(up, l1->val, l2->val));
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {
            cur->next = new ListNode(helper(up, l1->val, 0));
            cur = cur->next;
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            cur->next = new ListNode(helper(up, 0, l2->val));
            cur = cur->next;
            l2 = l2->next;
        }

        if (up != 0)
            cur->next = new ListNode(helper(up, 0, 0));

        root = root->next;

        return root;
    }

    inline int helper(int &up, int l1val, int l2val)
    {
        int ret;

        if (up == 1)
        {
            ret = l1val + l2val + 1;

            if (ret < 10)
                up = 0;
        }
        else
        {
            ret = l1val + l2val;
        }

        if (ret >= 10)
        {
            ret -= 10;
            up = 1;
        }

        return ret;
    }
};