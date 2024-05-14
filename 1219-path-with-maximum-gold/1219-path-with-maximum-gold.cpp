class Solution {
public:
    
    int dfs(vector<vector<int>> &grid, int m, int n, int i, int j)
    {
        if (i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)
        {
            return 0;
        }
        
        int currGold = grid[i][j];
        grid[i][j] = 0;
        
        int up = dfs(grid, m, n, i-1, j);
        int down = dfs(grid, m, n, i+1, j);
        int left = dfs(grid, m, n, i, j-1);
        int right = dfs(grid, m, n, i, j+1);
        
        grid[i][j] = currGold;
        return currGold+max(max(up, down), max(left, right));
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        int maxGold = 0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (grid[i][j] > 0)
                {
                    maxGold = max(maxGold, dfs(grid, m, n, i, j));
                }
            }
        }        
        
        return maxGold;
    }
};