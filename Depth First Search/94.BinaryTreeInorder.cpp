/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode *root)
    {
        //goes through to the furthest left node, then returns this, the bubbles up returns root then returns right, bubble again and repeat
        helper(root);
        return res;
    }

    void helper(TreeNode *root)
    {
        if (root == NULL)
            return;

        helper(root->left);
        res.push_back(root->val);
        helper(root->right);
    }
};