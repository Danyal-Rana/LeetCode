class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        if (matrix.empty())
        {
            return result;
        }
        
        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;
        
        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd)
        {
            for (int col = colBegin; col <= colEnd; ++col)
            {
                result.push_back(matrix[rowBegin][col]);
            }
            rowBegin++;

            for (int row = rowBegin; row <= rowEnd; ++row) 
            {
                result.push_back(matrix[row][colEnd]);
            }
            colEnd--;

            if (rowBegin <= rowEnd) 
            {
                for (int col = colEnd; col >= colBegin; --col) 
                {
                    result.push_back(matrix[rowEnd][col]);
                }
            }
            rowEnd--;

            if (colBegin <= colEnd) 
            {
                for (int row = rowEnd; row >= rowBegin; --row) 
                {
                    result.push_back(matrix[row][colBegin]);
                }
            }
            colBegin++;
        }
        return result;
    }
};
