class Solution {
public:
    int helper(vector<int>& nums, int &target, int i, int currSum)
    {
        if (i == nums.size())
        {
            if(currSum == target)
                return 1;
            else
                return 0;
        }
        
        int plusOne = helper(nums, target, i+1, currSum+nums[i]);
        int minusOne = helper(nums, target, i+1, currSum-nums[i]);

        return plusOne+minusOne;
    }
    int findTargetSumWays(vector<int>& nums, int target)
    {
        return helper(nums, target, 0, 0);        
    }
};