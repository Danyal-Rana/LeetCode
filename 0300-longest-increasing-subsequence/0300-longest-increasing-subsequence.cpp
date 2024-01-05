class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tail(n, 0);
        int c = 0;
        tail[0] = nums[0];
        int len = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > tail[len - 1]) {
                tail[len] = nums[i];
                len++;
            } else {
                c = ceilIndex(tail, 0, len - 1, nums[i]);
                tail[c] = nums[i];
            }
        }

        return len;
    }

private:
    int ceilIndex(vector<int>& tail, int l, int r, int x) {
        while (r > l) {
            int m = l + (r - l) / 2;
            if (tail[m] >= x) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};