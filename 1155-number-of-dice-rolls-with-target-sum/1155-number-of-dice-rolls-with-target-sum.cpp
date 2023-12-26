class Solution {
public:
    
    int mod = 1e9+7;
    
    int helper (int dices, int faces, int target, vector<vector<int>>&dp)
    {
        if (target < 0)
        {
            return 0;
        }
        
        if (dices == 0)
        {
            return target == 0;
        }
        
        if (dp[dices][target] != -1)
        {
            return dp[dices][target];
        }
        
        int ans = 0;
        
        for (int i=1; i<=faces; i++)
        {
            ans = (ans + helper (dices-1, faces, target-i, dp)) % mod;
        }
        
        dp[dices][target] = ans;
        
        return ans;
    }
    
    
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp (n+1, vector<int>(target+1, -1));
        
        return helper (n, k, target, dp);
    }
};