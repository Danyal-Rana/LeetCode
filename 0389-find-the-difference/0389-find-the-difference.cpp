class Solution {
public:
    char findTheDifference(string s, string t)
    {
        vector<int> myVector (26, 0);
        
        for (int i=0; i<t.size(); i++)
        {
            myVector[t[i]-'a']++;
        }
        
        for (int i=0; i<s.size(); i++)
        {
            myVector[s[i]-'a']--;
        }
        
        for (int i=0; i<26; i++)
        {
            if (myVector[i] == 1)
            {
                return i+'a';
            }
        }
        return 'a';
    }
};