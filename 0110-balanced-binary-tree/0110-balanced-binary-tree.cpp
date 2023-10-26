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
    
    int height (TreeNode *root)
    {
        if (root==NULL)
        {
            return 0;
        }
        
        int left = height (root->left);
        int right = height (root->right);
        
        int ans = max (left, right) + 1;
        
        return ans;
    }
    
    bool isBalanced(TreeNode* root)
    {
        if (root == NULL)
        {
            return true;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        int dif = abs(left-right);
        bool ans = (dif<=1);
        
        bool l = isBalanced (root->left);
        bool r = isBalanced (root->right);
        
        if (ans && l && r)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};