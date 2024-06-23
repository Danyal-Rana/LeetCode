class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit)
    {
        int ans = 0;
        deque<int> minQue;
        deque<int> maxQue;
        int l = 0;
        int r = 0;

        while (r < nums.size())
        {
            int temp = nums[r];

            while (!minQue.empty() and nums[minQue.back()]>=temp)
            {
                minQue.pop_back();
            }
            minQue.push_back(r);

            while (!maxQue.empty() and nums[maxQue.back()]<=temp)
            {
                maxQue.pop_back();
            }
            maxQue.push_back(r);

            int mini = nums[minQue.front()];
            int maxi = nums[maxQue.front()];

            if (maxi-mini > limit)
            {
                l++;
                if (l > minQue.front())
                {
                    minQue.pop_front();
                }
                if (l > maxQue.front())
                {
                    maxQue.pop_front();
                }
            }
            else
            {
                ans = max(ans, r-l+1);
                r++;
            }
        }

        return ans;
    }
};