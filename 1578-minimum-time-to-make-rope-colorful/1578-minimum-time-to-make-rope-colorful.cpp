class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int res = 0;
        int maxCost = 0;
        int sumCost = 0;
        int n = colors.size();
        
        for (int i=0; i<n; i++)
        {
            if (i>0 && colors[i]!=colors[i-1])
            {
                res += sumCost - maxCost;
                sumCost = maxCost = 0;
            }
            sumCost += neededTime[i];
            maxCost = max (maxCost, neededTime[i]);
        }
        
        res += sumCost - maxCost;
        return res;
    }
};