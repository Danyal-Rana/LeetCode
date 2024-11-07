class Solution {
public:
    int largestCombination(vector<int>& candidates)
    {
        vector<int> count(24, 0);
        int ans = 0;

        for (int i=0; i<24; i++)
        {
            for (auto &num : candidates)
            {
                if ((num & (1 << i)) != 0)
                {
                    count[i]++;
                }
            }

            ans = max(ans, count[i]);
        }

        return ans;
    }
};