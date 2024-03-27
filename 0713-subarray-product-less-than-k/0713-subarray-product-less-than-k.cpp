class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        int start = 0;
        
        int end = 0;
        
        int myProduct= 1;
        
        int myCounter=0;
        
        int n = nums.size();
        
        if (k <= 1)
            return 0;
        
        while (end < n)
        {
            myProduct *= nums[end];
            
            while (myProduct >= k)
            {
                myProduct /= nums[start++];
            }
            
            myCounter += 1 + (end - start);
            end++;
        }
        
        
        return myCounter;
    }
};