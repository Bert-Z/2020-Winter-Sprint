/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <queue>

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return root;

        queue<TreeNode *> bt;
        bt.push(root);

        while (!bt.empty())
        {
            TreeNode *cur = bt.front();

            TreeNode *l = cur->left;
            TreeNode *r = cur->right;

            cur->left = r;
            cur->right = l;

            if (l != NULL)
                bt.push(l);
            if (r != NULL)
                bt.push(r);

            bt.pop();
        }
        return root;
    }
};