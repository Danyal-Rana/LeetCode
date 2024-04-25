class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> myVector (n, 0);
        
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (myVector[j]+1 > myVector[i])
                    {
                        myVector[i] = myVector[j]+1;
                    }
                }
            }
        }
        
        int maxIndex = 0;
        for (int i=0; i<n; i++)
        {
            if (myVector[i] > myVector[maxIndex])
                maxIndex = i;
        }
        
        return myVector[maxIndex] + 1;
    }
};