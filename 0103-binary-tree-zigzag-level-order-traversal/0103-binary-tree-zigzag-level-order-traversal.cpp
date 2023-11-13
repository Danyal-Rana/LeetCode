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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> zigzag;
        if (root == NULL)
        {
            return zigzag;
        }
        queue<TreeNode*> q;
        
        q.push (root);
        int count = 1;
        
        while (!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            
            for (int i=0; i<n; i++)
            {
                TreeNode *t = q.front();
                q.pop();
                temp.push_back (t->val);
                
                if (t->left)
                {
                    q.push (t->left);
                }
                if (t->right)
                {
                    q.push (t->right);
                }
            }
            if (count%2 != 0)
            {
                count++;
                zigzag.push_back (temp);
            }
            else if (count%2 == 0)
            {
                count++;
                reverse (temp.begin(), temp.end());
                zigzag.push_back (temp);
            }
        }
        return zigzag;
    }
};