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
    
    void helper(TreeNode *root, bool isLeft, int &sum)
    {
        if (isLeft && !root->right && !root->left)
        {
            sum += root->val;
            return;
        }
        
        if (root->left)
            helper(root->left, true, sum);
        if (root->right)
            helper(root->right, false, sum);
    }
    
    
    int sumOfLeftLeaves(TreeNode* root)
    {
        int sum = 0;
        
        if (!root)
            return sum;
        
        helper (root, false, sum);
        
        return sum;
    }
};