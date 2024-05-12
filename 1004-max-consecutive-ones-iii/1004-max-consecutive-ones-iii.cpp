class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int start = 0;
        int zeroCounter = 0;
        int maxOnes = 0;
        
        for (int end=0; end<nums.size(); end++)
        {
            if (nums[end] == 0)
            {
                zeroCounter++;
            }
            
            while (zeroCounter > k)
            {
                if (nums[start]==0)
                {
                    zeroCounter--;
                }
                
                start++;
            }
            
            maxOnes = max(maxOnes, end-start+1);
        }
        
        return maxOnes;
    }
};