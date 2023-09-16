class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        int sArray[26] = {0};
        int tArray[26] = {0};

        for (int i=0; i<s.size(); i++)
        {
            sArray[s[i]-'a']++;
        }

        for (int i=0; i<t.size(); i++)
        {
            tArray[t[i]-'a']++;
        }

        for (int i=0; i<26; i++)
        {
            if (sArray[i] != tArray[i])
            {
                return false;
            }
        }
        return true;
    }
};