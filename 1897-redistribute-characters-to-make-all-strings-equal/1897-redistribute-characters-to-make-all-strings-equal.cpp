class Solution {
public:
    bool makeEqual(vector<string>& words)
    {
        unordered_map<char, int> m;
        
        for (auto i : words)
        {
            for (auto j : i)
            {
                m[j]++;
            }
        }
        
        int n = words.size();
        
        for (auto i : m)
        {
            if (i.second%n == 0)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};