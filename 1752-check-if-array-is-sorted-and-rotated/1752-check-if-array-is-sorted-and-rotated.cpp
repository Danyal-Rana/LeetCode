class Solution {
public:
    bool check(vector<int>& nums)
    {
        int myCounter = 0;
        
        int vSize = nums.size();
        
        for (int i=0; i<vSize-1; i++)
        {
            if (nums[i] > nums[i+1])
            {
                myCounter++;
            }
        }
        
        
        if (myCounter == 0 || (myCounter == 1) && !(nums[0] < nums[vSize - 1]))
        {
            return true;
        }
        
        return false;
    }
};