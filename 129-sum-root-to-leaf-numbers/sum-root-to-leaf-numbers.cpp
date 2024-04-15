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
class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {
        if (!root)
        {
            return 0;
        }        

        int ans = 0;

        helper(root, 0, ans);

        return ans;
    }

    void helper(TreeNode *root, int val, int &ans)
    {
        int curr = 10*val + root->val;

        if (!root->right && !root->left)
        {
            ans += curr;
            return;
        }

        if (root->left)
        {
            helper(root->left, curr, ans);
        }
        if (root->right)
        {
            helper(root->right, curr, ans);
        }
    }
};