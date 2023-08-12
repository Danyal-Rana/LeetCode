class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        sort (nums.begin(), nums.end());
        
        int vSize = nums.size();
        
        int aSum = (vSize * (vSize + 1))/2;
        
        int mySum = accumulate(nums.begin(), nums.end(), 0);
        
        return aSum - mySum;
    }
};