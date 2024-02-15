class Solution {
public:
    long long largestPerimeter(vector<int>& nums)
    {
        sort (nums.begin(), nums.end());
        long long preSum = nums[0] + nums[1];
        long long ans = 0;
        
        for (int i=2; i<nums.size(); i++)
        {
            if (preSum > nums[i])
            {
                ans = max(ans, preSum+nums[i]);
            }
            preSum += nums[i];
        }
        
        return (ans == 0) ? -1 : ans;
    }
};