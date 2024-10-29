class Solution {
public:
    int m,n;
    vector<int> directions {-1, 0, 1};

    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if (dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        int moves = 0;

        for (int &dir : directions)
        {
            int currRow = row+dir;
            int currCol = col+1;

            if (currRow>=0 && currRow<m && currCol>=0 && currCol<n && grid[currRow][currCol]>grid[row][col])
            {
                moves = max(moves, 1+dfs(currRow, currCol, grid, dp));                
            }
        }
        return dp[row][col]=moves;
    }

    int maxMoves(vector<vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp (m, vector<int>(n, -1));

        int ans = 0;
        for (int i=0; i<m; i++)
        {
            ans = max(ans, dfs(i, 0, grid, dp));
        }
        return ans;
    }
};