class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int maxVal = INT_MIN;
        int ans = 0;
        int currStreak = 0;

        for (int num : nums)
        {
            if (num > maxVal)
            {
                maxVal = num;
                ans = 0;
                currStreak = 0;
            }

            if (maxVal == num)
            {
                currStreak++;
            }
            else
            {
                currStreak = 0;
            }
            ans = max(ans, currStreak);
        }

        return ans;
    }
};