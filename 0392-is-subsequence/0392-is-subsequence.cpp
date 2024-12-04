class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int n = t.size();
        int m = s.size();

        int i = 0;
        int j = 0;

        while (i<n && j<m)
        {
            if (t[i]==s[j])
            {
                j++;
            }
            i++;
        }

        return j==m; 
    }
};