class Solution {
public:
    int rob(vector<int>& nums) {
        int dp0 = 0, dp1 = 0;
        for (auto& num : nums) {
            int curr = max(dp0 + num /* take */, dp1 /* skip (not take) */);
            dp0 = dp1;
            dp1 = curr;
        }
        return max(dp0, dp1);
    }
};