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
    void solve(TreeNode *leftChild, TreeNode *rightChild, int level)
    {
        if (!leftChild)
            return;
        if (!rightChild)
            return;

        if (level%2==1)
        {
            int temp = leftChild->val;
            leftChild->val = rightChild->val;
            rightChild->val = temp;
        }

        solve(leftChild->left, rightChild->right, level+1);
        solve(leftChild->right, rightChild->left, level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root)
    {
        solve(root->left, root->right, 1);
        return root;        
    }
};