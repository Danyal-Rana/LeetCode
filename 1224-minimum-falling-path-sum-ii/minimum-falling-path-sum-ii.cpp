class Solution {
public:
    // time/space: O(n ^ 3)/O(n ^ 2)
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        int result = INT_MAX;
        for (int c = 0; c < grid[0].size(); c++) {
            result = min(result, helper(grid, dp, 0, c));
        }
        return result;
    }
private:
    const int INVALID = 1e9;
    int helper(vector<vector<int>>& grid, vector<vector<int>>& dp, int r, int c) {
        // terminate
        if (r == (grid.size() - 1)) return grid[r][c];
        if (dp[r][c] != -1) return dp[r][c];

        // enumerate
        int best = INVALID;
        for (int nc = 0; nc < grid[0].size(); nc++) {
            if (nc == c) continue;
            best = min(best, helper(grid, dp, r + 1, nc));
        }
        return dp[r][c] = grid[r][c] + best;
    }
};