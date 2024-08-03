#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFlipsToPalindrome(vector<vector<int>>& grid, bool isRow) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int totalFlips = 0;
        
        if (isRow) 
        {
            for (int i = 0; i < m; ++i) 
            {
                int flips = 0;
                for (int j = 0; j < n / 2; ++j) 
                {
                    if (grid[i][j] != grid[i][n - 1 - j]) 
                    {
                        flips++;
                    }
                }
                totalFlips += flips;
            }
        } 
        else 
        {
            for (int j = 0; j < n; ++j) 
            {
                int flips = 0;
                for (int i = 0; i < m / 2; ++i) 
                {
                    if (grid[i][j] != grid[m - 1 - i][j]) 
                    {
                        flips++;
                    }
                }
                totalFlips += flips;
            }
        }
        
        return totalFlips;
    }
    
    int minFlips(vector<vector<int>>& grid) 
    {
        int rowFlips = minFlipsToPalindrome(grid, true);
        int colFlips = minFlipsToPalindrome(grid, false);
        
        return min(rowFlips, colFlips);
    }
};