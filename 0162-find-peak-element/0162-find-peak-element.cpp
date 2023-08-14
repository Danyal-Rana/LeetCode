class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int sInd = 0;
        int eInd = nums.size()-1;

        int mInd = (sInd+eInd)/2;

        while (sInd < eInd)
        {
            if (nums[mInd] < nums[mInd+1])
            {
                sInd = sInd+1;
            }
            else
            {
                eInd = mInd;
            }
            mInd = (sInd+eInd)/2;
        }        
        return mInd;
    }
};