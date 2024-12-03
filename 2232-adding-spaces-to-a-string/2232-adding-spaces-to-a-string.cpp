class Solution {
public:
    string addSpaces(string s, vector<int>& spaces)
    {
        int n = s.size();
        int m = spaces.size();

        int i=0;
        string ans = "";
        for (int j=0; j<n; j++)
        {
            if (i<m and spaces[i]==j)
            {
                ans += ' ';
                ans += s[j];
                i++;
            }
            else
            {
                ans += s[j];
            }
        }
        return ans;
    }
};