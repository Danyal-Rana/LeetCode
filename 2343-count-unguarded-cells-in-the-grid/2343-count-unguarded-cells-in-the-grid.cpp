class Solution {
public:

    void makeGaurded(int row, int col, vector<vector<int>>& grid)
    {
        for(int i = row-1; i >= 0; i--) 
        {
            if(grid[i][col] == 2 || grid[i][col] == 3) 
            {
                break;
            }
            grid[i][col] = 1;
        }

        for(int i = row+1; i < grid.size(); i++) 
        {
            if(grid[i][col] == 2 || grid[i][col] == 3) 
            {
                break;
            }
            grid[i][col] = 1;
        }

        for(int j = col-1; j >= 0; j--) {
            if(grid[row][j] == 2 || grid[row][j] == 3) 
            {
                break;
            }
            grid[row][j] = 1;
        }

        for(int j = col+1; j < grid[0].size(); j++) 
        {
            if(grid[row][j] == 2 || grid[row][j] == 3) 
            {
                break;
            }
            grid[row][j] = 1;
        }

    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto &ele : walls)
        {
            grid[ele[0]][ele[1]] = 3;
        }

        for (auto &ele : guards)
        {
            grid[ele[0]][ele[1]] = 2;
        }

        for (auto &ele : guards)
        {
            makeGaurded(ele[0], ele[1], grid);
        }

        int ans = 0;

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};