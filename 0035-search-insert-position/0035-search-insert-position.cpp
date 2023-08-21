class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int lInd = 0;
        int rInd = nums.size()-1;

        if (target > nums[rInd])
        {
            return rInd+1;
        }

        while (lInd <= rInd)
        {
            int mInd = lInd + (rInd - lInd)/2;

            if (target == nums[mInd])
            {
                return mInd;
            }

            else if (target > nums[mInd])
            {
                lInd = mInd + 1;
            }

            else if (target < nums[mInd])
            {
                rInd = mInd - 1;
            }
        }
        return lInd;
    }
};