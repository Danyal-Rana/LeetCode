class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size()-1;

        int ans = -1;

        while (left < right)
        {
            int mid = (left+right)/2;

            if (nums[mid] >= k)
            {
                right = mid;
            }
            else 
            {
                left = mid+1;
            }
        }
        return left;
    }
};