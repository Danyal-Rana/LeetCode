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
    TreeNode* replaceValueInTree(TreeNode* root)
    {
        if (root==NULL)
        {
            return root;
        }

        queue<TreeNode *> q;
        vector<int> levelSum;
        q.push(root);

        while (!q.empty())
        {
            int currLevelSum = 0;
            int n = q.size();

            while (n--)
            {
                TreeNode *temp = q.front();
                q.pop();
                currLevelSum += temp->val;

                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            levelSum.push_back(currLevelSum);
        }

        // for cousins
        q.push(root);
        root->val = 0;
        int i = 1;

        while (!q.empty())
        {
            int n = q.size();

            while (n--)
            {
                TreeNode *temp = q.front();
                q.pop();

                // siblings sum
                int siblingSum = temp->left ? temp->left->val : 0;
                siblingSum += temp->right ? temp->right->val : 0;

                if (temp->left)
                {
                    temp->left->val = levelSum[i]-siblingSum;
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    temp->right->val = levelSum[i]-siblingSum;
                    q.push(temp->right);
                }
            }
            i++;
        }
        return root;
    }
};