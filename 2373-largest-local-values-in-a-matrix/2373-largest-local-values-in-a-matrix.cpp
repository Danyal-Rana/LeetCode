class Solution {
public:
    
    int findMax(vector<vector<int>> &grid, int i, int j)
    {
        int myMax = INT_MIN;
        
        for (int x=i; x<i+3; x++)
        {
            for (int y=j; y<j+3; y++)
            {
                myMax = max(myMax, grid[x][y]);
            }
        }
        
        return myMax;
    }
    
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> myGrid(n-2, vector<int>(n-2));
        
        for (int i=0; i<n-2; i++)
        {
            for (int j=0; j<n-2; j++)
            {
                myGrid[i][j] = findMax(grid, i, j);
            }
        }
        
        return myGrid;
    }
};