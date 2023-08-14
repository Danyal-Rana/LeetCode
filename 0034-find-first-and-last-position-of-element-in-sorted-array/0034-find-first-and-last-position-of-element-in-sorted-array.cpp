int firstOcc (vector<int> &arr, int n, int k)
{
    int sInd = 0;
    int eInd = n-1;
    
    int ans = -1;
    
    int mInd = (sInd + eInd)/2;
    
    while (sInd <= eInd)
    {
        if (arr[mInd] == k)
        {
            ans =  mInd;
            eInd = mInd - 1;
        }
        
        else if (arr[mInd] > k)
        {
            eInd = mInd - 1;
        }
        
        else if (arr[mInd] < k)
        {
            sInd = mInd + 1;
        }
        mInd = (sInd + eInd)/2;
    }
    return ans;
}

int lastOcc (vector<int> &arr, int n, int k)
{
    int sInd = 0;
    int eInd = n-1;
    
    int ans = -1;
    
    int mInd = (sInd + eInd)/2;
    
    while (sInd <= eInd)
    {
        if (arr[mInd] == k)
        {
            ans =  mInd;
            sInd = mInd + 1;
        }
        
        else if (arr[mInd] > k)
        {
            eInd = mInd - 1;
        }
        
        else if (arr[mInd] < k)
        {
            sInd = mInd + 1;
        }
        mInd = (sInd + eInd)/2;
    }
    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();

        vector <int> myVector;
    
        myVector.push_back(firstOcc(nums, n, target));
        myVector.push_back(lastOcc(nums, n, target));
    
        return myVector;        
    }
};