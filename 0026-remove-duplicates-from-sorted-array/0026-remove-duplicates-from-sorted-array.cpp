class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + i + 1);
            }
        }
        return nums.size();
    }
};
