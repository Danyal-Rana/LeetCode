class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int myCounter = 0;

        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[myCounter++] = nums[i];
            }
        }

        return myCounter;
    }
};