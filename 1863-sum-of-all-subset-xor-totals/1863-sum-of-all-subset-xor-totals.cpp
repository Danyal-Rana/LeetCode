class Solution {
public:
    int subsetXORSum(vector<int>& nums)
    {
        int n = nums.size();
        int sum = 0;
        
        for (int i=1; i<(1<<n); i++)
        {
            int cSum = 0;
            
            for (int j=0; j<n; j++)
            {
                if (i & (1<<j))
                {
                    cSum ^= nums[j];
                }
            }
            sum += cSum;
        }
        return sum;
    }
};