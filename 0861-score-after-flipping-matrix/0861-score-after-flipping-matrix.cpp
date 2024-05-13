class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int nRows = grid.size(), nCols = grid[0].size();

        // Flipping a row
        auto flipRow = [&](int row) {
            for (int col = 0; col < nCols; ++col) {
                grid[row][col] = 1 - grid[row][col];
            }
        };

        // Flipping a column
        auto flipCol = [&](int col) {
            for (int row = 0; row < nRows; ++row) {
                grid[row][col] = 1 - grid[row][col];
            }
        };

        // Convert row to decimal
        auto checkRow = [&](const vector<int>& nums) {
            int result = 0;
            for (int num : nums) {
                result = result * 2 + num;
            }
            return result;
        };

        // Ensuring the first column has all 1s
        for (int row = 0; row < nRows; ++row) {
            if (grid[row][0] == 0) {
                flipRow(row);
            }
        }

        // Optimize columns for maximum number of 1s
        for (int col = 1; col < nCols; ++col) {
            int countOne = 0;
            for (int row = 0; row < nRows; ++row) {
                if (grid[row][col] == 1) {
                    countOne++;
                }
            }
            if (countOne * 2 < nRows) { // More 0s than 1s
                flipCol(col);
            }
        }

        // Calculate the total 

        int totalScore = 0;
        for (const auto& row : grid) {
            totalScore += checkRow(row);
        }

        return totalScore;
    }
};