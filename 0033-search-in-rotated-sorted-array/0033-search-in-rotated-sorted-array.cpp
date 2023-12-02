class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int lInd = 0;
        int rInd = nums.size()-1;

        while (lInd <= rInd)
        {
            int mInd = lInd + (rInd-lInd)/2;

            if (nums[mInd] == target)
            {
                return mInd;
            }

            if (nums[lInd] <= nums[mInd])
            {
                if (nums[lInd]<=target && nums[mInd]>target)
                {
                    rInd = mInd-1;
                }
                else
                {
                    lInd = mInd+1;
                }
            }

            else
            {
                if (nums[rInd]>=target && nums[mInd]<target)
                {
                    lInd = mInd + 1;
                }
                else
                {
                    rInd = mInd-1;
                }
            }
        }
        return -1;
    }
};