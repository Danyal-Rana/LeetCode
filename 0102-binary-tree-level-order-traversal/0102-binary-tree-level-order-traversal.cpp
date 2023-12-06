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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> myVector;
        
        if (root==NULL)
        {
            return myVector;
        }
        
        queue<TreeNode*> q;
        q.push (root);
        
        while (!q.empty())
        {
            int s = q.size();
            vector<int> myV;
            
            for (int i=0; i<s; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                myV.push_back (temp->val);
                
                if (temp->left)
                {
                    q.push (temp->left);
                }
                if (temp->right)
                {
                    q.push (temp->right);
                }
            }
            myVector.push_back (myV);
        }
        
        
        return myVector;
    }
};