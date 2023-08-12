class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        vector <int> myVector;
        int myCounter = 0;
        int max = 0;
        
        for (int i=0; i<nums.size(); i++)
        {
        
            if (nums[i] == 1)
            {
                myCounter++;
                if (max < myCounter)
                {
                    max = myCounter;
                }
            }
            else
            {
                myCounter = 0;
            }
        }
        return max;
    }
};