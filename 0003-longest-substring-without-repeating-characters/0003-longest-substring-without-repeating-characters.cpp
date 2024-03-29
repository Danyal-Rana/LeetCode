#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int maxLen = 0;
        int start = -1;
        unordered_map<char, int> dict;
        
        for (int i = 0; i < s.size(); i++) 
        {
            if (dict.find(s[i]) != dict.end() && dict[s[i]] > start) 
            {
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        
        return maxLen;
    }
};