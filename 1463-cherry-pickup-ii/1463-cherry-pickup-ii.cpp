class Solution {
public:
    int row, col;
    int dp[70][70][70];

    int solve(int r, int c1, int c2, vector<vector<int>>& grid){
        if(c1 < 0 || c1 >= col || c2 < 0 || c2 >= col || r >= row) return 0;
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int ans = 0;
        if(c1 == c2) ans = grid[r][c1];
        else ans = grid[r][c1] + grid[r][c2];

        int a = solve(r+1, c1-1, c2-1, grid);
        int b = solve(r+1, c1-1, c2, grid);
        int c = solve(r+1, c1-1, c2+1, grid);
        int d = solve(r+1, c1, c2-1, grid);
        int e = solve(r+1, c1, c2, grid);
        int f = solve(r+1, c1, c2+1, grid);
        int g = solve(r+1, c1+1, c2-1, grid);
        int h = solve(r+1, c1+1, c2, grid);
        int i = solve(r+1, c1+1, c2+1, grid);

        ans += max(i, max( max(max(a, b), max(c, d)), max(max(e, f), max(g, h)) ));
        return dp[r][c1][c2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        memset(dp, -1, sizeof(dp));
        
        return solve(0, 0, col-1, grid);
    }
};