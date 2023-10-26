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
    
    vector<int> postOrderTraversal (TreeNode *root, vector<int> &myVector)
    {
        if (root != NULL)
        {
            postOrderTraversal (root->left, myVector);
            postOrderTraversal (root->right, myVector);
            myVector.push_back (root->val);
        }
        return myVector;
    }
    
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> myVector;
        return postOrderTraversal (root, myVector);
    }
};