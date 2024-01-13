class Solution {
public:
    int minSteps(string s, string t)
    {
        unordered_map<char, int> m;
        
        for (auto i : s)
            m[i]++;
        
        for (auto i : t)
            m[i]--;
        
        int ans = 0;
        
        for (auto i : m)
            ans += abs (i.second);
        
        return ans/2;
    }
};