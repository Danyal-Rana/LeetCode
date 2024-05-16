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
    bool evaluateTree(TreeNode* root)
    {
        if (root->val == 0)
            return false;
        else if (root->val == 1)
            return true;
        else if (root->val == 2)
        {
            bool leftBool = evaluateTree(root->left);
            bool rightBool = evaluateTree(root->right);
            return leftBool or rightBool;
        }
        else if (root->val == 3)
        {
            bool leftBool = evaluateTree(root->left);
            bool rightBool = evaluateTree(root->right);
            return leftBool and rightBool;
        }
        return false;
    }
};