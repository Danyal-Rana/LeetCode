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

    bool checkValid (TreeNode *root, long int upperBound, long int lowerBound)
    {
        if (root == NULL)
        {
            return true;
        }

        if (root->val < upperBound && root->val > lowerBound)
        {
            bool leftAns = checkValid (root->left, root->val, lowerBound);
            bool rightAns = checkValid (root->right, upperBound, root->val);

            return leftAns && rightAns;
        }
        else
        {
            return false;
        }
    }

    bool isValidBST(TreeNode* root)
    {
        long int upperBound = 2147483648;
        long int lowerBound = -2147483649;

        bool ans = checkValid (root, upperBound, lowerBound);

        return ans;         
    }
};