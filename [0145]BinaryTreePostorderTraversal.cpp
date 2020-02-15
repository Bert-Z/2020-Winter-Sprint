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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> nodeStack;
        map<TreeNode *, bool> nmap;
        vector<int> ret;

        while (root != NULL || !nodeStack.empty())
        {
            for (; root != NULL && nmap.find(root) == nmap.end(); root = root->left)
            {
                nodeStack.push(root);
                nmap[root] = false;
            }

            TreeNode *now = nodeStack.top();

            if (now->right != NULL && nmap.find(now->right) == nmap.end())
                root = now->right;
            else if ((now->left == NULL && now->right == NULL) || (now->left == NULL && nmap[now->right]) || (nmap[now->left] && now->right == NULL) || (nmap[now->left] && nmap[now->right]))
            {
                nmap[now] = true;
                ret.push_back(now->val);
                nodeStack.pop();
            }
        }

        return ret;
    }
};