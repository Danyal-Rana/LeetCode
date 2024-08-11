class Solution {
public:
    int m, n;

    void dfs (vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &vis)
    {
        if (i<0 || i>=m || j<0 || j>=n || grid[i][j]==0 || vis[i][j])
        {
            return;
        }

        vis[i][j] = true;

        dfs(grid, i+1, j, vis);
        dfs(grid, i-1, j, vis);
        dfs(grid, i, j+1, vis);
        dfs(grid, i, j-1, vis);
    }

    int noOfIslands (vector<vector<int>> &grid)
    {
        int islands = 0;
        vector<vector<bool>> vis(m, vector<bool>(n));

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    dfs(grid, i, j, vis);
                    islands++;
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();

        int islands = noOfIslands(grid);

        if (islands > 1 or islands == 0)
        {
            return 0; // we have only one island
        }
        else
        {
            // checking, if we can disconnect in one day
            for (int i=0; i<m; i++)
            {
                for (int j=0; j<n; j++)
                {
                    if (grid[i][j]==1)
                    {
                        // make it water
                        grid[i][j] = 0;

                        // now count the islands
                        islands = noOfIslands (grid);

                        // making it again island
                        grid[i][j] = 1;

                        if (islands > 1 or islands == 0)
                        {
                            return 1;
                        }
                    }
                }
            }
        }
        return 2;
    }
};