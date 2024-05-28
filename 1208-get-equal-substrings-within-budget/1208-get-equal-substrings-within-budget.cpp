class Solution {
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int maxLen = 0;
        int curCost = 0;
        int left = 0;
        
        for(int right=0; right<s.size(); right++)
        {
            if (curCost+abs(s[right]-t[right]) <= maxCost)
            {
                curCost += abs(s[right]-t[right]);
                maxLen = max(maxLen, right-left+1);
            }
            else
            {
                curCost += abs(s[right]-t[right]);
                
                while (left<=right and curCost>maxCost)
                {
                    curCost -= abs(s[left]-t[left++]);
                }
            }
        }
        return maxLen;
    }
};