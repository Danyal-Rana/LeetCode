class Solution {
public:
    int helper(int n, vector<int> &dp)
    {
        if (n < 0)
            return 0;
        else if (dp[n] != -1)
            return dp[n];
        
        int singleStep = helper(n-1, dp);
        int doubleStep = helper(n-2, dp);

        return dp[n]=singleStep+doubleStep;
    }

    int climbStairs(int n)
    {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        return helper(n, dp);        
    }
};