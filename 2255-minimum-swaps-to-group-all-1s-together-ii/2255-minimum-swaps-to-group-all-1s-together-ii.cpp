class Solution {
public:
    int minSwaps(vector<int>& nums)
    {
        int n = nums.size();
        int totalOne = 0;

        for (int i=0; i<n; i++)
        {
            if (nums[i]==1)
            {
                totalOne++;
            }
        }

        int left = 0;
        int windowOne = 0;
        int maxWindowOne = 0;

        for (int right=0; right<2*n; right++)
        {
            if (nums[right%n]==1)
            {
                windowOne++;
            }
            if (right-left+1 > totalOne)
            {
                windowOne -= nums[left%n];
                left++;
            }
            maxWindowOne = max(maxWindowOne, windowOne);
        }

        return totalOne - maxWindowOne;
    }
};