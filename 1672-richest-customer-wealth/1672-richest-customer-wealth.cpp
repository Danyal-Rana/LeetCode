class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts)
    {
        int maxSum = 0;
        
        for (auto i : accounts)
        {
            int curSum = 0;
            for (auto j : i)
            {
                curSum += j;
            }
            maxSum = max(maxSum, curSum);
        }
        
        return maxSum;
    }
};