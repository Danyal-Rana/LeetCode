class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int n = nums.size();
        
        int myIndex = 0;
        
        for (int i=0; i<n; i++)
        {
            if (nums[i] != 0)
            {
                nums[myIndex] = nums[i];
                myIndex++;
            }
        }
        
        for (int i=myIndex; i<n; i++)
        {
            nums[i] = 0;
        }
    }
};