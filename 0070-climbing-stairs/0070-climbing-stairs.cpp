class Solution {
public:

    int dp[46];
    int helper(int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int singleStep = helper(n-1);
        int doubleStep = helper(n-2);

        return dp[n] = singleStep+doubleStep;
    }

    int climbStairs(int n)
    {
        memset(dp, -1, sizeof(dp));
        return helper(n);        
    }
};