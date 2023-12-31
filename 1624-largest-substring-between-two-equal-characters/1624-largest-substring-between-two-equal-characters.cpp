class Solution {
public:
    int maxLengthBetweenEqualCharacters(std::string s)
    {
        unordered_map<char, int> m;
        int ans = -1;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            
            if (m.count(c))
            {
                ans = max(ans, i - m[c] - 1);
            } 
            else 
            {
                m[c] = i;
            }
        }

        return ans;
    }
};