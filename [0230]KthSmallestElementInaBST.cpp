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
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> nodeStack;
        int count = 0;

        while (root != NULL || !nodeStack.empty())
        {
            for (; root != NULL; root = root->left)
                nodeStack.push(root);

            count++;
            if (count == k)
                return nodeStack.top()->val;

            if (nodeStack.top()->right != NULL)
                root = nodeStack.top()->right;

            nodeStack.pop();
        }

        return 0;
    }
};