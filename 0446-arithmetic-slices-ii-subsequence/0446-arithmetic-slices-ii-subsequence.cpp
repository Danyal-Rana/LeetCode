class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<unordered_map<long, long>> dp(n + 1);
        
        long a = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                long diff = (long) nums[i] - long(nums[j]);
                
                a += dp[j][diff];
                
                dp[i][diff] += dp[j][diff];
                
                dp[i][diff]++;
            }
        }
        
        return a;
    }
};