class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int lInd = 0;
        int rInd = nums.size() - 1;

        while (lInd < rInd)
        {
            int mInd = lInd + (rInd - lInd) / 2;

            if (nums[mInd] < nums[rInd])
            {
                rInd = mInd;
            }
            else if (nums[mInd] > nums[rInd])
            {
                lInd = mInd + 1;
            }
            else
            {
                rInd--;
            }
        }

        return nums[lInd];
    }
};
