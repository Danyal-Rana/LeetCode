class Solution {
public:
    int largestPerimeter(vector<int>& nums)
    {
        int perimeter = 0;

        sort (nums.begin(), nums.end());

        for (int i=nums.size()-2; i>=1; i--)
        {
            if (nums[i-1]+nums[i] > nums[i+1])
            {
                perimeter = nums[i-1]+nums[i]+nums[i+1];
                break;
            }
        }

        return perimeter;
    }
};