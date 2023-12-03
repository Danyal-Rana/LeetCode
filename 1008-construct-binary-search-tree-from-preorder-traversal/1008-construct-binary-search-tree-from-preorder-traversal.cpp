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
    TreeNode* helper(vector<int>& preorder, int& idx, int minVal, int maxVal)
    {
        if (idx >= preorder.size())
        {
            return NULL;
        }
        
        int val = preorder[idx];
        
        if (val < minVal || val > maxVal)
        {
            return NULL;
        }
        
        TreeNode* node = new TreeNode(val);
        idx++;        
        node->left = helper(preorder, idx, minVal, val - 1);
        node->right = helper(preorder, idx, val + 1, maxVal);
        
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        int idx = 0;
        return helper(preorder, idx, INT_MIN, INT_MAX);
    }
};