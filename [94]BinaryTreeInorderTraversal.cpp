/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>
#include<vector>

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        inorder(ret, root);
        return ret;
    }

    void inorder(vector<int> &ret, TreeNode *root)
    {
        if (root == NULL)
            return;
        else
        {
            inorder(ret, root->left);
            ret.push_back(root->val);
            inorder(ret, root->right);
            return;
        }
    }
};

// iterative solution

// vector<int> inorderTraversal(TreeNode* root) {
//         vector<TreeNode*> s;
//         vector<int> v;
//         while (root != NULL || !s.empty()) {
//             for (; root != NULL; root = root->left)
//                 s.push_back(root);
//             v.push_back(s.back()->val);
//             root = s.back()->right;
//             s.pop_back();
//         }
//         return v;
//     }