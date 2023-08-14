class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int sInd = 0;
        int eInd = arr.size()-1;

        int mInd = (sInd+eInd)/2;

        while (sInd < eInd)
        {
            if (arr[mInd] < arr[mInd+1])
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