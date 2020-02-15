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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> nodeStack;
        vector<int> ret;

        if (root == NULL)
            return ret;

        nodeStack.push(root);

        while (!nodeStack.empty())
        {
            TreeNode *top = nodeStack.top();
            TreeNode *l = top->left, *r = top->right;
            ret.push_back(top->val);
            nodeStack.pop();

            if (r != NULL)
                nodeStack.push(r);

            if (l != NULL)
                nodeStack.push(l);
        }

        return ret;
    }
};