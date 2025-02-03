class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        if (nums.empty()) 
            return 0;

        int maxInc = 1;
        int maxDec = 1;
        int tempInc = 1;
        int tempDec = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) 
            {
                tempInc++;
                tempDec = 1;
            } else if (nums[i] < nums[i-1]) 
            {
                tempDec++;
                tempInc = 1;
            } else {
                tempInc = 1;
                tempDec = 1;
            }

            maxInc = max(maxInc, tempInc);
            maxDec = max(maxDec, tempDec);
        }

        return max(maxInc, maxDec);
    }
};