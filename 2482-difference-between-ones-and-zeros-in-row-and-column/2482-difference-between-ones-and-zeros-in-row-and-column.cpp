class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> result (n, vector<int>(m, 0));
        
        vector <pair<int, int>> row01;
        vector <pair<int, int>> col01;
        
        for (int i=0; i<n; i++)
        {
            int zero = 0;
            int one = 0;
            
            for (int j=0; j<m; j++)
            {
                if (grid[i][j] == 0)
                {
                    zero++;
                }
                else
                {
                    one++;
                }
            }
            row01.push_back ({zero, one});
        }
        
        for (int i=0; i<m; i++)
        {
            int zero = 0;
            int one = 0;
            
            for (int j=0; j<n; j++)
            {
                if (grid[j][i] == 0)
                {
                    zero++;
                }
                else
                {
                    one++;
                }
            }
            col01.push_back ({zero, one});
        }
        
        for (int i=0; i<n; i++)
        {            
            for (int j=0; j<m; j++)
            {
                result[i][j] = row01[i].second+col01[j].second-row01[i].first-col01[j].first;
            }
        }
        
        return result;
    }
};