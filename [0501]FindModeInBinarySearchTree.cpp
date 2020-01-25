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
#include<map>
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
    map<int, int> countmap;
    vector<int> findMode(TreeNode *root)
    {
        inorder(root);

        vector<int> ret;
        int maxvalue = countmap.begin()->second;
        for (auto it = countmap.begin(); it != countmap.end(); it++)
        {
            if (it->second > maxvalue)
            {
                maxvalue = it->second;
                ret.clear();
                ret.push_back(it->first);
            }
            else if (it->second == maxvalue)
                ret.push_back(it->first);
        }
        return ret;
    }

    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        
        inorder(root->left);
        countplus(root->val);
        inorder(root->right);
        return;
    }

    inline void countplus(int val)
    {
        if (countmap.find(val) != countmap.end())
            countmap[val]++;
        else
            countmap[val] = 0;
        
        return;
    }
};