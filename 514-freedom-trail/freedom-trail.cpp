class Solution {
public:
    
    vector<vector<int>> dp;
    
    int helper (string &ring, string &key, int ptr, int index)
    {
        int n = ring.size();
        int m = key.size();
        
        //base condition
        if (index >= m)
        {
            return 0;
        }
        
        if (dp[index][ptr] != -1)
        {
            return dp[index][ptr];
        }
        int steps = 1e9;
        
        //choices
        for (int i=0; i<n; i++)
        {
            if (ring[i] == key[index])
            {
                steps = min (steps, min(abs(i-ptr), n-abs(i-ptr))+1+ helper(ring, key, i, index+1));
            }
        }
        return dp[index][ptr] = steps;
    }
    
    
    int findRotateSteps(string ring, string key)
    {
        int ptr = 0;
        int index = 0;
        
        int n = ring.size();
        int m = key.size();
        
        dp.assign(m+1, vector<int>(n+1, -1));
        
        return helper (ring, key, ptr, index);
    }
};