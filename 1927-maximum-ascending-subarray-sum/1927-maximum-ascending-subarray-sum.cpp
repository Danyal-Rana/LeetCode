class Solution {
public:
    int maxAscendingSum(vector<int>& nums)
    {
        if(nums.size()==1)
            return nums[0];
        int maxSum = 0;

        for(int i=1; i<nums.size(); i++)
        {
            int tempSum = nums[i-1];

            while(i<nums.size() && nums[i-1]<nums[i])
            {
                tempSum += nums[i++];
            }

            maxSum = max(maxSum, tempSum);
        }

        return maxSum;
    }
};