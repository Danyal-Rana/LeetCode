class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums)
    {
        int maxInc = 0;
        int maxDec = 0;
        int tempInc = 0;
        int tempDec = 0;

        for(int i=0; i<nums.size()-1; i++)
        {
            if (nums[i] < nums[i+1])
            {
                maxDec = max(maxDec, tempDec);
                tempDec = 0;
                tempInc++;
            }
            else if (nums[i] > nums[i+1])
            {
                maxInc = max(maxInc, tempInc);
                tempInc = 0;
                tempDec++;
            }
            else
            {
                maxInc = max(maxInc, tempInc);
                maxDec = max(maxDec, tempDec);
                tempInc = 0;
                tempDec = 0;
            }
        }

        maxInc = max(maxInc, tempInc);
        maxDec = max(maxDec, tempDec);

        return max(maxInc, maxDec)+1;        
    }
};