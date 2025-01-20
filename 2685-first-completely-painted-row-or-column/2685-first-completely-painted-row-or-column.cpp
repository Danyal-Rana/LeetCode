class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> mp;

        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                int val = mat[i][j];
                mp[val] = {i, j};
            }
        }

        vector<int> rowCountPaint(m, 0);
        vector<int> colCountPaint(n, 0);

        for(int i = 0; i < arr.size(); i++) 
        {
            int val = arr[i];
            auto [row, col] = mp[val];

            rowCountPaint[row]++;
            colCountPaint[col]++;

            if(rowCountPaint[row] == n || colCountPaint[col] == m) 
            {
                return i;
            }
        }
        return -1;
    }
};