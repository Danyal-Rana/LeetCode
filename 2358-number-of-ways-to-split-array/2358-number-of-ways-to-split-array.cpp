class Solution {
public:
    int waysToSplitArray(vector<int>& nums)
    {
        int n = nums.size();
        int ways = 0;

        vector<long long> preSum(n, 0);
        preSum[0] = nums[0];
        for (int i=1; i<n; i++)
        {
            preSum[i] = preSum[i-1]+nums[i];
        }

        vector<long long> postSum(n, 0);
        postSum[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            postSum[i] = postSum[i+1]+nums[i];
        }

        for(int i=0; i<n-1; i++)
        {
            if(preSum[i] >= postSum[i+1])
                ways++;
        }
        return ways;
    }
};