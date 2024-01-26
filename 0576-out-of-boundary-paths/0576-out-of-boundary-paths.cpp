class Solution {
typedef long long ll;
ll mod = 1e9+7;
public:
    int findPaths(int m, int n, int move, int i, int j) {
        vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>>(n + 1, vector<ll>(move + 1, -1)));
        return solve(m,n,move,i,j,dp);
    }
    ll solve(int m, int n, int move, int i, int j,vector<vector<vector<ll>>>& dp){
        if(i < 0 || j < 0 || i >= m || j >= n) return 1;
        if(move == 0) return 0;
        if(dp[i][j][move] != -1) return dp[i][j][move];
        ll ans = (solve(m,n,move-1,i+1,j,dp) + solve(m,n,move-1,i,j+1,dp) + solve(m,n,move-1,i-1,j,dp) + solve(m,n,move-1,i,j-1,dp))%mod;
        return dp[i][j][move] = ans;
    }
};