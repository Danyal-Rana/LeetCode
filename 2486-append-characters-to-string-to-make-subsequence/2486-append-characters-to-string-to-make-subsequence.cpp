class Solution {
public:
    int appendCharacters(string s, string t)
    {
        int i = 0;
        int j = 0;
        
        while (i < s.size())
        {
            while (i<s.size() && s[i]!=t[j])
            {
                i++;
            }
            
            if (i == s.size())
            {
                return t.size()-j;
            }
            
            i++;
            j++;
        }
        
        return t.size()-j;
    }
};