class Solution {
public:
    int longestSquareStreak(vector<int>& nums)
    {
        unordered_map<int, int> mp;
        int maxStreak = -1;
        sort(nums.begin(), nums.end());

        for (auto &num : nums)
        {
            int root = (int)sqrt(num);

            if (root*root == num && mp.find(root)!=mp.end())
            {
                mp[num] = mp[root]+1;
            }
            else
            {
                mp[num] = 1;
            }

            maxStreak = max(maxStreak, mp[num]);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};