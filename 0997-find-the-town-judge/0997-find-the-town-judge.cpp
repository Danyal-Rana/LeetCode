class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<int> out (n+1);
        vector<int> in (n+1);
        
        for (auto i : trust)
        {
            out[i[0]]++;
            in[i[1]]++;
        }
        
        for (int i=1; i<=n; i++)
        {
            if (in[i]==n-1 && out[i]==0)
                return i;
        }
        
        return -1;
    }
};