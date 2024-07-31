class Solution {
public:
    string convert(string s, int numRows)
    {
        int n = s.size();
        int numCols = n;

        vector<vector<char>> a(numRows, vector<char>(numCols, '$'));
        int i=0;
        int j=0;
        int k=0;

        while (k<n and i<numRows and j<numCols)
        {
            // filling along the col
            a[i++][j] = s[k++];

            // last row is filled and now filling the diagonal
            if (i == numRows)
            {
                i -= 2;
                j++;

                while (k<n and i>=1)
                {
                    a[i--][j++] = s[k++];
                }

                if (i<0)
                {
                    i=0;
                }
            }
        }

        string ans = "";
        for (auto i : a)
        {
            for (auto j : i)
            {
                if (j != '$')
                {
                    ans += j;
                }
            }
        }

        return ans;
    }
};