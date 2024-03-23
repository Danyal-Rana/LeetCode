class Solution {
public:
    
    int dp[301];
    
    bool helper(int index, string s, set<string>& mySet)
    {
        if (index == s.size())
            return 1;
        
        if (dp[index] != -1)
            return dp[index];
        
        string temp;
        
        for (int i=index; i<s.size(); i++)
        {
            temp += s[i];
            
            if (mySet.find(temp) != mySet.end())
            {
                if (helper(i+1, s, mySet))
                {
                    return dp[index]=1;
                }
            }
        }
        return dp[index]=0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict)
    {
        memset (dp, -1, sizeof dp);
        
        set<string> mySet;
        for (auto i : wordDict)
        {
            mySet.insert(i);
        }
        
        return helper (0, s, mySet);
    }
};