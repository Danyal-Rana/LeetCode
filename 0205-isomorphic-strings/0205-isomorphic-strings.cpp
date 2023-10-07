class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map <char, char> myMap;

        for (int i=0; i<s.size(); i++)
        {
            char sChar = s[i];
            char tChar = t[i];

            if (myMap.find(sChar) != myMap.end())
            {
                if (myMap[sChar] != tChar)
                {
                    return false;
                }
            }

            else
            {
                for (const auto &pair : myMap)
                {
                    if (pair.second == tChar)
                    {
                        return false;
                    }
                }
                myMap [sChar] = tChar;
            }
        }

        return true;        
    }
};