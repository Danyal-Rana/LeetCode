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

    TreeNode *buildTree(vector<int> inOrder, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        int mid = (start+end)/2;
        TreeNode *root = new TreeNode (inOrder[mid]);
        root->left = buildTree(inOrder, start, mid-1);
        root->right = buildTree(inOrder, mid+1, end);

        return root;
    }

    void inorderTraversal(TreeNode *root, vector<int> &inOrder)
    {
        if (root)
        {
            inorderTraversal(root->left, inOrder);
            inOrder.push_back(root->val);
            inorderTraversal(root->right, inOrder);
        }
    }

    TreeNode* balanceBST(TreeNode* root)
    {
        vector<int> inOrder;
        inorderTraversal(root, inOrder);
        int n = inOrder.size();
        root = buildTree(inOrder, 0, n-1);
        return root;        
    }
};