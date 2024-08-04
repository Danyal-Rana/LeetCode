class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        vector<int> temp;

        for (int i=0; i<n; i++)
        {
            int cSum = 0;
            for (int j=i; j<n; j++)
            {
                cSum += nums[j];
                temp.push_back(cSum);
            }
        }

        sort(temp.begin(), temp.end());

        long long ans = 0;
        int mod = 1e9+7;

        for (int i=left-1; i<=right-1; i++)
        {
            ans = (ans + temp[i]) % mod;
        }

        return ans;
    }
};