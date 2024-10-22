class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        if (!root)
        {
            return -1;
        }

        queue<TreeNode*> q1;
        q1.push(root);

        vector<long long> ans;

        while (!q1.empty())
        {
            queue<TreeNode*> q2;
            long long currSum = 0;

            while (!q1.empty())
            {
                TreeNode* temp = q1.front();
                q1.pop();
                currSum += temp->val;

                if (temp->left)
                {
                    q2.push(temp->left);
                }
                if (temp->right)
                {
                    q2.push(temp->right);
                }
            }

            ans.push_back(currSum);
            q1 = q2;
        }

        sort(ans.begin(), ans.end());
        if (k > ans.size())
        {
            return -1;
        }
        return ans[ans.size() - k];
    }
};