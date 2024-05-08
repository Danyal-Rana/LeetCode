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
    
    unordered_set<int> visited;
public:
    bool findTarget(TreeNode* root, int k)
    {
        if (!root)
        {
            return false;
        }
        
        if (visited.count(k-root->val))
        {
            return true;
        }
        
        visited.insert(root->val);
        
        return findTarget(root->left, k) or findTarget(root->right, k);
    }
};