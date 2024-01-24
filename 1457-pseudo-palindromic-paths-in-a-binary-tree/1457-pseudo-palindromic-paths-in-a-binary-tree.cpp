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
    
    void helper (TreeNode *root, vector<int> &myVector, int &myCounter)
    {
        if (root == NULL)
            return;
        
        myVector[root->val]++;
        
        helper (root->left, myVector, myCounter);
        helper (root->right, myVector, myCounter);
        
        if (root->left==NULL && root->right==NULL)
        {
            int flag = 0;
            
            for (int i=1; i<=9; i++)
            {
                if (myVector[i] & 1)
                    flag++;
            }
            
            if (flag==1 || flag==0)
                myCounter++;
        }
        myVector[root->val]--;
    }
    
    
    int pseudoPalindromicPaths (TreeNode* root)
    {
        int myCounter = 0;
        vector<int> myVector (10, 0);
        
        helper (root, myVector, myCounter);
        
        return myCounter;
    }
};