class Solution {
public:
    bool check(vector<vector<int>>& matrix, int row, int col, int p)
    {
        for (int i = 0; i < matrix.size(); i++) 
        {
            if (matrix[i][col] > p) 
            {
                return false;
            }
        }
        return true;
    }

    vector<int> luckyNumbers(vector<vector<int>>& matrix) 
    {
        vector<int> answer;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) 
        {
            int p = INT_MAX;
            int t;
            for (int j = 0; j < m; j++) 
            {
                if (matrix[i][j] < p) 
                {
                    t = j;
                    p = matrix[i][j];
                }
            }
            if (check(matrix, i, t, p) == true) 
            {
                answer.push_back(p);
            }
        }
        return answer;
    }
};