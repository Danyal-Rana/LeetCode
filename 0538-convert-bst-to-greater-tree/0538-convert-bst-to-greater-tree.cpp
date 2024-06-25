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

    void reverseInorder(TreeNode *root, int &sum)
    {
        if (root)
        {
            reverseInorder(root->right, sum);
            root->val += sum;
            sum = root->val;

            reverseInorder(root->left, sum);
        }
    }

    TreeNode* convertBST(TreeNode* root)
    {
        int sum = 0;
        reverseInorder(root, sum);
        return root;      
    }
};