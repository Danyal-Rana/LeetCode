// using 3 pointer approach
// if elements are in valid range update ans, otherwise updater trackers

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        int n = nums.size();
        long long ans = 0;
        int lastInvalidIndex = -1;
        int lastMinIndex = -1;
        int lastMaxIndex = -1;
        
        for (int i=0; i<n; i++)
        {
            if (nums[i]<=maxK and nums[i]>=minK)
            {
                if (nums[i] == minK)
                {
                    lastMinIndex = i;
                }
                if (nums[i] == maxK)
                {
                    lastMaxIndex = i;
                }
                
                ans += max(0, min(lastMinIndex, lastMaxIndex)-lastInvalidIndex);
            }
            else
            {
                lastInvalidIndex = i;
                lastMinIndex = -1;
                lastMaxIndex = -1;
            }
        }
        return ans;
        
    }
};