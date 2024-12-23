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
    int helper(vector<int> &arr)
    {
        int minSwaps = 0;
        vector<int> sortedArr(arr.begin(), arr.end());
        sort(sortedArr.begin(), sortedArr.end());

        unordered_map<int, int> mp;

        for (int i=0; i<arr.size(); i++)
        {
            mp[arr[i]] = i;
        }

        for (int i=0; i<arr.size(); i++)
        {
            if(arr[i]==sortedArr[i])
                continue;

            int realIdx = mp[sortedArr[i]];
            mp[arr[i]] = realIdx;
            swap(arr[realIdx], arr[i]);
            minSwaps++;
        }

        return minSwaps;
    }

    int minimumOperations(TreeNode* root)
    {
        queue<TreeNode*> que;
        int ans = 0;
        que.push(root);

        while(!que.empty())
        {
            int n = que.size();
            vector<int> arr;

            while(n--)
            {
                TreeNode *temp = que.front();
                que.pop();
                arr.push_back(temp->val);

                if(temp->left)
                    que.push(temp->left);
                if(temp->right)
                    que.push(temp->right);
            }

            ans += helper(arr);
        }

        return ans;
    }
};