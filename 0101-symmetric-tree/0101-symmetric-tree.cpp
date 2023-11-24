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
    bool helper (TreeNode *rootLeft, TreeNode *rootRight)
    {
        if (rootLeft!=NULL && rootRight==NULL || rootLeft==NULL && rootRight!=NULL)
        {
            return false;
        }
        if (rootLeft == NULL && rootRight == NULL)
        {
            return true;
        }
        
        bool leftSide = helper (rootLeft->left, rootRight->right);
        bool rightSide = helper (rootLeft->right, rootRight->left);
        bool value = (rootLeft->val == rootRight->val);
        
        return leftSide && rightSide && value;
    }
    
    bool isSymmetric(TreeNode* root)
    {
        if (root->right==NULL && root->left==NULL)
        {
            return true;
        }
        
        return helper (root->left, root->right);
    }
};