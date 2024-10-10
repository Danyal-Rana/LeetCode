class Solution {
public:
    int maxWidthRamp(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];

        // Fill rightMax to store the maximum value to the right of each element
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        int ans = 0;
        int i = 0;
        int j = 0;

        // Traverse using two pointers
        while (j < n)
        {
            // Ensure i doesn't go beyond j and increment it if nums[i] > rightMax[j]
            while (i < j && nums[i] > rightMax[j])
            {
                i++;
            }

            ans = max(ans, j - i);
            j++;
        }

        return ans;
    }
};