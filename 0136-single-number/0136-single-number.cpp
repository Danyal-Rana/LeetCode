class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        sort (nums.begin(), nums.end());

        int i=0;

        for (; i<nums.size()-1; i+=2)
        {
            if (nums[i] != nums[i+1])
            {
                break;
            }
        }
        return nums[i];        
    }
};