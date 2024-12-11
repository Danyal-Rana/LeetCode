class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k)
    {
        vector<pair<int, int>> ranges;
        int ans = 0;

        int n = nums.size();
        for (int i=0; i<n; i++)
        {
            int x = nums[i]-k;
            int y = nums[i]+k;
            ranges.push_back({x, y});
        }

        sort(ranges.begin(), ranges.end());

        deque<int> deq;

        for(auto &range : ranges)
        {
            while (!deq.empty() && deq.front() < range.first)
            {
                deq.pop_front();
            }

            deq.push_back(range.second);
            ans = max(ans, (int)deq.size());
        }

        return ans;
    }
};