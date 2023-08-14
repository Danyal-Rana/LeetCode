class Solution {
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> myMap;
        
        myMap['I'] = 1;
        myMap['V'] = 5;
        myMap['X'] = 10;
        myMap['L'] = 50;
        myMap['C'] = 100;
        myMap['D'] = 500;
        myMap['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(myMap[s[i]] < myMap[s[i+1]])
            {
                ans = ans - myMap[s[i]];
            }
            else
            {
                ans = ans + myMap[s[i]];
            }
        }
        return ans;
    }
};