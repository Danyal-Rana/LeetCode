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
    
    void inOrder (TreeNode *root, vector<int> &myVector)
    {
        if (root == NULL)
            return;
        
        inOrder (root->left, myVector);
        myVector.push_back (root->val);
        inOrder (root->right, myVector);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        vector <int> myVector;
        inOrder (root, myVector);
        
        int ans = 0;
        
        for (int i=0; i<myVector.size(); i++)
        {
            if (myVector[i]>=low && myVector[i]<=high)
                ans += myVector[i];
        }
        return ans;
    }
};