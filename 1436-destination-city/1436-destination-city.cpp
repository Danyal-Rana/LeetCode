class Solution {
public:
    string destCity(vector<vector<string>>& paths)
    {
        unordered_map<string, int> mp;
        
        int n = paths.size();
        
        for (int i=0; i<n; i++)
        {
            mp[paths[i][0]]++;
        }
        
        for (int i=0; i<n; i++)
        {
            if (mp[paths[i][1]] < 1)
            {
                return paths[i][1];
            }
        }
        
        return "";
    }
};