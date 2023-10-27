class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int rows = image.size();
        int cols = image[0].size();
        
        vector<vector<int>> result(rows, vector<int>(cols, 0)); 
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result[i][cols - 1 - j] = (image[i][j] == 0) ? 1 : 0;
            }
        }
        
        return result;
    }
};
