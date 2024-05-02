class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        sort (nums.begin(), nums.end());

        int left = 0;
        int right = nums.size()-1;

        while (left < right)
        {
            if (nums[left] >= 0)
            {
                break;
            }
            else if (abs(nums[left]) == nums[right])
            {
                return nums[right];
            }
            else if (abs(nums[left]) > nums[right])
            {
                left++;
            }
            else if (abs(nums[left]) < nums[right])
            {
                right--;
            }
        }

        return -1;
    }
};