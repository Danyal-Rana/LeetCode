#define mod 1000000007
#define ll long long int

class Solution {
public:
    
    ll dp[100007][3][3];
    
    ll solve (int n, int absentCounter, int lateCounter)
    {
        if (n == 0)
        {
            return 1;
        }
        
        if (dp[n][absentCounter][lateCounter] != -1)
        {
            return dp[n][absentCounter][lateCounter];
        }
        
        ll ans = 0;
        
        ans = solve (n-1, absentCounter, 0);
        
        if (absentCounter < 1)
        {
            ans = (ans + solve(n-1, absentCounter+1, 0)) % mod;
        }
        
        if (lateCounter < 2)
        {
            ans = (ans + solve(n-1, absentCounter, lateCounter+1)) % mod;
        }
        
        return dp[n][absentCounter][lateCounter] = ans%mod;
    }
    
    
    int checkRecord(int n)
    {
        memset (dp, -1, sizeof(dp));
        return solve (n, 0, 0);
    }
};