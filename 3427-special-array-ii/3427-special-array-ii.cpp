class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        int m = queries.size();
        vector<bool> ans(m, true);

        vector<int> violation(n - 1, 0);

        for (int i = 0; i < n - 1; ++i) 
        {
            if (nums[i] % 2 == nums[i + 1] % 2) 
            {
                violation[i] = 1;
            }
        }

        vector<int> prefix(n, 0);
        for (int i = 1; i < n; ++i) 
        {
            prefix[i] = prefix[i - 1] + violation[i - 1];
        }

        for (int q = 0; q < m; ++q) {
            int start = queries[q][0];
            int end = queries[q][1];

            if (prefix[end] - prefix[start] > 0) 
            {
                ans[q] = false;
            }
        }

        return ans;
    }
};