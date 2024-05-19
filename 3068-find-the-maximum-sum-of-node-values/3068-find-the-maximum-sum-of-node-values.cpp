class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
    {
        long long sum = 0;
        long long myCounter = 0;
        long long balliKaBakra = INT_MAX;
        
        for (auto i : nums)
        {
            if ((i^k) > i)
            {
                sum += i^k;
                balliKaBakra = min(balliKaBakra, ((long long)(i^k))-i);
                myCounter++;
            }
            else
            {
                sum += i;
                balliKaBakra = min(balliKaBakra, ((long long)i) - (i^k));
            }
        }
        
        if (myCounter%2==0)
            return sum;
        
        return sum - balliKaBakra;
    }
};