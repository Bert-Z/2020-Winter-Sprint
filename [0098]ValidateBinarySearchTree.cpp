/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> nodeStack;
        int last, now;
        bool flag = false;

        while (root != NULL || !nodeStack.empty())
        {
            for (; root != NULL; root = root->left)
                nodeStack.push(root);

            if (!flag)
            {
                flag = true;
                now = nodeStack.top()->val;
                last = now;
            }
            else
            {
                last = now;
                now = nodeStack.top()->val;
                if (last >= now)
                    return false;
            }

            if (nodeStack.top()->right != NULL)
                root = nodeStack.top()->right;

            nodeStack.pop();
        }

        return true;
    }
};