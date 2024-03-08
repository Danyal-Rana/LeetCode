class Solution {
public:
    bool areOccurrencesEqual(string s)
    {
        unordered_map <char, int> myMap;
        
        for (auto i : s)
        {
            myMap[i]++;
        }
        
        int firstFreq = myMap[s[0]];
        
        for (auto i : myMap)
        {
            if (i.second != firstFreq)
                return false;
        }
        
        return true;
    }
};