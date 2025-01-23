class Solution {
public:
    int countServers(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        vector<int> rowArr (n, 0);
        vector<int> colArr (m, 0);

        for(int row=0; row<n; row++)
        {
            for (int col=0; col<m; col++)
            {
                if (grid[row][col]==1)
                {
                    rowArr[row]++;
                    colArr[col]++;
                }
            }
        }

        for(int row=0; row<n; row++)
        {
            for (int col=0; col<m; col++)
            {
                if (grid[row][col]==1 && (rowArr[row]>1 || colArr[col]>1))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};