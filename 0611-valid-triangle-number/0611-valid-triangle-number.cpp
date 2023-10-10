class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        int myCounter = 0;

        sort (nums.begin(), nums.end());

        for (int i=nums.size()-1; i>=2; i--)
        {
            int leftIndex = 0;
            int rightIndex = i-1;

            while (leftIndex < rightIndex)
            {
                if (nums[leftIndex]+nums[rightIndex] > nums[i])
                {
                    myCounter = myCounter+(rightIndex-leftIndex);
                    rightIndex--;
                }
                else
                {
                    leftIndex++;
                }
            }
        }
        
        return myCounter;
    }
};