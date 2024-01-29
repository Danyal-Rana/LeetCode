class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> m;
        
        for (auto c : magazine)
        {
            if (m.find(c) == m.end())
            {
                m[c] = 1;
            }
            else
            {
                m[c]++;
            }
        }
        
        for (auto i : ransomNote)
        {
            if (m.find(i) != m.end() && m[i] > 0)
            {
                m[i]--;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};