class Solution {
public:
    int helper(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (i>=matrix.size() || j>=matrix[0].size())
        {
            return 0;
        }
        if (matrix[i][j]==0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = helper(i, j+1, matrix, dp);
        int diag = helper(i+1, j+1, matrix, dp);
        int bottom = helper(i+1, j, matrix, dp);

        return dp[i][j] = 1+min({right, diag, bottom});
    }

    int countSquares(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (matrix[i][j]==1)
                {
                    ans += helper(i, j, matrix, dp);
                }
            }
        }

        return ans;
    }
};