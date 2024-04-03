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
    
    TreeNode *helper (vector<int> &preorder, vector<int> &inorder, int &i, int left, int right)
    {
        if (left>right)
        {
            return NULL;
        }
        
        int p = left;
        
        while (inorder[p] != preorder[i])
        {
            p++;
        }
        
        i++;
        TreeNode *t = new TreeNode (inorder[p]);
        t->left = helper (preorder, inorder, i, left, p-1);
        t->right = helper (preorder, inorder, i, p+1, right);
        
        return t;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int n = inorder.size();
        int i = 0;
        return helper (preorder, inorder, i, 0, n-1);
    }
};