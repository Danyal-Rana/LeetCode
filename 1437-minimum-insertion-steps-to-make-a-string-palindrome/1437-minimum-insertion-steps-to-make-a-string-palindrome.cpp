class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int helper(string &s, int i, int j) 
    {
        if (i >= j) 
        {
            return 0;
        }
        if (dp[i][j] != -1) 
        {
            return dp[i][j];
        }
        if (s[i] == s[j]) 
        {
            return dp[i][j] = helper(s, i + 1, j - 1);
        }

        return dp[i][j] = 1 + min(helper(s, i + 1, j), helper(s, i, j - 1));
    }

    int minInsertions(string s) 
    {
        n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return helper(s, 0, n - 1);
    }
};