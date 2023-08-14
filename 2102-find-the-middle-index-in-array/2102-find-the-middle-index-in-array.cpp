class Solution {
public:
    int findMiddleIndex(vector<int>& nums)
    {
        long long int leftSum = 0;
        long long int rightSum = accumulate(nums.begin(), nums.end(), 0);

        for (int i=0; i<nums.size(); i++)
        {
            rightSum = rightSum - nums[i];

            if (leftSum == rightSum)
            {
                return i;
            }
            leftSum = leftSum + nums[i];
        }
        return -1;
    }
};