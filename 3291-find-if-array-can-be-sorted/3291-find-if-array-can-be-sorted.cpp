class Solution {
public:
    bool canSortArray(vector<int>& nums)
    {
        int n = nums.size();

        bool flag;

        for (int i=0; i<n; i++)
        {
            flag = false;
            for (int j=0; j<n-i-1; j++)
            {
                if (nums[j] <= nums[j+1])
                {
                    continue;
                }
                else
                {
                    if (__builtin_popcount(nums[j])==__builtin_popcount(nums[j+1]))
                    {
                        swap (nums[j], nums[j+1]);
                        flag = true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            if (!flag)
            {
                return true;
            }
        }
        return true;
    }
};