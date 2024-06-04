class Solution {
public:
    int longestPalindrome(string s)
    {
        int ans = 0;
        unordered_map<char, int> myMap;
        
        for (auto c : s)
        {
            myMap[c]++;
        }
        
        bool oddCheck = false;
        
        for (auto i : myMap)
        {
            if (i.second%2 == 0)
            {
                ans += i.second;
            }
            else
            {
                oddCheck = true;
                ans += i.second-1;
            }
        }
        
        if (oddCheck)
        {
            ans += 1;
        }
        
        
        return ans;
    }
};