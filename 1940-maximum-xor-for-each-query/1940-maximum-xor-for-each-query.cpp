class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        int n = nums.size();

        vector<int> ans(n);

        // finding total XOR
        int XOR = 0;

        for (int i=0; i<n; i++)
        {
            XOR ^= nums[i];
        }

        // to find flip, we need mask having all set bits
        int mask = (1 << maximumBit) - 1;

        for (int i=0; i<n; i++)
        {
            int k = XOR^mask; // k (flipped value of XOR)
            ans[i] = k;
            XOR ^= nums[n-i-1];
        }

        return ans;
    }
};