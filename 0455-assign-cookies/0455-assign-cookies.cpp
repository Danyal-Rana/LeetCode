class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        sort (g.rbegin(), g.rend());
        sort (s.rbegin(), s.rend());
        
        int cur = 0;
        int total = 0;
        
        int n = g.size();
        int m = s.size();
        
        for (int i=0; i<n; i++)
        {
            if (cur < m && g[i]<=s[cur])
            {
                total++;
                cur++;
            }
        }
        return total;
    }
};