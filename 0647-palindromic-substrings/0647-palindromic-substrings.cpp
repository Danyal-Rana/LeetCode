class Solution {
public:
    
    int helper(string s, int left, int right)
    {
        int ans = 0;
        while (left>=0 && right<s.size() && s[left]==s[right])
        {
            ans++;
            left--;
            right++;
        }
        return ans;
    }
    
    int countSubstrings(string s)
    {
        int myAns = 0;
        int n = s.size();
        
        for (int i=0; i<n; i++)
        {
            int oddAns = helper(s, i, i);
            int evenAns = helper(s, i, i+1);
            myAns += oddAns + evenAns;
        }
        
        return myAns;
    }
};