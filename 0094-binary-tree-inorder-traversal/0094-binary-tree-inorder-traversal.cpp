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
    vector<int> inOrderTraversal (TreeNode *root, vector<int> &myVector)
    {
        if (root != nullptr)
        {
            inOrderTraversal (root->left, myVector);
            myVector.push_back (root->val);
            inOrderTraversal (root->right, myVector);
        }
        return myVector;
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector <int> myVector;
        return inOrderTraversal (root, myVector);
    }
};