#include <queue>
#include <iostream>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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
    int maxDepth(TreeNode *root)
    {

        if (!root)
        {
            return 0;
        }

        queue<TreeNode *> tree;
        tree.push(root);

        int depth = 0;

        while (!tree.empty())
        {
            int treesize = tree.size();
            for (int i = 0; i < treesize; i++)
            {
                TreeNode *cur = tree.front();

                if (cur->left)
                    tree.push(cur->left);
                if (cur->right)
                    tree.push(cur->right);

                tree.pop();
            }
            depth++;
        }

        return depth;
    }
};