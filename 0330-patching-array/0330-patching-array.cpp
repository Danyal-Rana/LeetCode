class Solution {
public:
    int minPatches(vector<int>& nums, int n) 
    {
        long int minPossiblePatches = 0;
        long int maxNum = 0;
        long int i = 0;
        long int sz = nums.size();

        while (maxNum < n)
        {
            if (i < sz and maxNum+1 >= nums[i])
            {
                maxNum += nums[i++];
            }
            else
            {
                minPossiblePatches++;
                maxNum += (maxNum + 1);
            }
        }

        return minPossiblePatches;
    }
};