class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)
            return 0;
        int count = grid[i][j];
        grid[i][j] = 0;
        for (vector<int> dir: dirs)
        {
            int i_ = i+dir[0];
            int j_ = j+dir[1];

            count += dfs(i_, j_, grid);
        }

        return count;
    }
    int findMaxFish(vector<vector<int>>& grid)
    {
        int ans = 0;

        m = grid.size();
        n = grid[0].size();

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]>0)
                {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};