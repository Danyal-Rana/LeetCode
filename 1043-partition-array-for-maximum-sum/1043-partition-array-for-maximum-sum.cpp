class Solution {
public:
    
    int helper (int ind, vector<int> &arr, int k, int n, vector<int> &dp)
    {
        if (ind == n)
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        
        int length= 0;
        int maxi = INT_MIN;
        
        int maxAns = INT_MIN;
        
        for (int i=ind; i<min(ind+k, n); i++)
        {
            length++;
            
            maxi = max (maxi, arr[i]);
            
            int sum = length*maxi + helper(i+1, arr, k, n, dp);
            
            maxAns = max(maxAns, sum);
        }
        
        return dp[ind] = maxAns;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        int n = arr.size();
        
        vector<int> dp(n, -1);
        
        return helper (0, arr, k, n, dp);
    }
};