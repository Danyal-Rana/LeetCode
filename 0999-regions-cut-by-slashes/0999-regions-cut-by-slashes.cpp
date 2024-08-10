class Solution {
public:

    void dfs (vector<vector<int>> &matrix, int i, int j)
    {
        if (i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]==1)
        {
            return;
        }

        // marking visited
        matrix[i][j] = 1;

        // checking surroundings
        dfs(matrix, i+1, j);
        dfs(matrix, i-1, j);
        dfs(matrix, i, j+1);
        dfs(matrix, i, j-1);
    }

    int regionsBySlashes(vector<string>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int regions = 0;
        vector<vector<int>> matrix(rows*3, vector<int>(cols*3, 0));

        // populating matrix
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
            {
                if (grid[i][j] == '/')
                {
                    matrix[i*3 +0][j*3 +2] = 1;
                    matrix[i*3 +1][j*3 +1] = 1;
                    matrix[i*3 +2][j*3 + 0] = 1;
                }
                else if (grid[i][j] == '\\')
                {
                    matrix[i*3 +0][j*3 + 0] = 1;
                    matrix[i*3 +1][j*3 +1] = 1;
                    matrix[i*3 +2][j*3 +2] = 1;
                }
            }
        }

        // applying number of islands
        for (int i=0; i<matrix.size(); i++)
        {
            for (int j=0; j<matrix[0].size(); j++)
            {
                if (matrix[i][j]==0)
                {
                    dfs(matrix, i, j);
                    regions++;
                }
            }
        }

        return regions;
    }
};