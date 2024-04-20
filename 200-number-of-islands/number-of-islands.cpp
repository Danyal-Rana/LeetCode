class Solution {
public:
    void markIsland(vector<vector<char>>& grid, int i, int j, int row, int col) {
        grid[i][j] = '0';
        if (i > 0 && grid[i-1][j] == '1') 
            markIsland(grid, i-1, j, row, col);
        if (i < row-1 && grid[i+1][j] == '1')
            markIsland(grid, i+1, j, row, col);
        if (j > 0 && grid[i][j-1] == '1')
            markIsland(grid, i, j-1, row, col);
        if (j < col-1 && grid[i][j+1] == '1')
            markIsland(grid, i, j+1, row, col);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '0')
                    continue;
                res++;
                markIsland(grid, i, j, row, col);
            }
        }
        return res;
    }
};