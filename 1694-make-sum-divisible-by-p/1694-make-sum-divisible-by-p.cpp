class Solution {
public:
    int minSubarray(vector<int>& nums, int p)
    {
        int sum = 0;
        int ans = nums.size();

        for (int &num : nums)
        {
            sum = (sum+num)%p;
        }

        int target = sum%p;

        if (target == 0)
        {
            return 0;
        }

        unordered_map<int, int> mp;
        int currSum = 0;
        mp[0] = -1;

        for (int i=0; i<nums.size(); i++)
        {
            currSum = (currSum+nums[i])%p;

            int x = (currSum-target+p)%p;

            if (mp.find(x) != mp.end())
            {
                ans = min(ans, i-mp[x]);
            }

            mp[currSum] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};