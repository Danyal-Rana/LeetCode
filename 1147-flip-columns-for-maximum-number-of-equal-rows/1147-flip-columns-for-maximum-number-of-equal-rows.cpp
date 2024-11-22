class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> mp;

        for (auto &row : matrix)
        {
            string rowsNature = "";

            int firstVal = row[0];
            for (int i=0; i<n; i++)
            {
                rowsNature += (row[i]==firstVal) ? "S" : "B";
            }

            mp[rowsNature]++;
        }

        int maxSameRows = 0;
        for (auto &it : mp)
        {
            maxSameRows = max(maxSameRows, it.second);
        }

        return maxSameRows;
    }
};