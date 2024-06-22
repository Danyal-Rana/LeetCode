class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        return helper(nums, k) - helper(nums, k-1);        
    }

    int helper(vector<int>&nums, int k)
    {
        if (k < 0)
        {
            return 0;
        }

        int l = 0;
        int r = 0;
        int sum = 0;
        int myCounter = 0;

        while (r < nums.size())
        {
            sum += nums[r]%2;

            while (sum > k)
            {
                sum -= (nums[l++]%2);                
            }

            myCounter += r-l+1;
            r++;
        }

        return myCounter;
    }
};