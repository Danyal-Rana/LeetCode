class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        // Array to track the count of bits set in each position (0 to 31)
        vector<int> hash(32, 0);  
        
        int l = 0, r = 0;    // Pointers for the sliding window
        int n = nums.size();  // Size of the input array
        int num = 0;          // Current OR of the window
        int ans = INT_MAX;    // Minimum length of subarray with OR >= k

        while (r < n) {
            // Update OR with the current element nums[r]
            num |= nums[r];
            
            // Update bit counts for nums[r]
            for (int i = 0; i < 32; i++) {
                if (nums[r] & (1 << i)) { // Check if the i-th bit is set
                    hash[i]++;
                }
            }
            
            // Once the OR of the window is >= k, try to minimize the window
            while (l <= r && num >= k) {
                // Update the minimum subarray length
                ans = min(ans, r - l + 1);
                
                // Remove nums[l] from the window
                for (int i = 0; i < 32; i++) {
                    if (nums[l] & (1 << i)) { // Check if the i-th bit is set
                        hash[i]--;
                        if (hash[i] == 0) {
                            // If the count of this bit becomes zero, remove it from OR
                            num -= (1 << i);
                        }
                    }
                }
                // Shrink the window from the left
                l++;
            }
            
            // Expand the window by moving the right pointer
            r++;
        }
        
        // If no valid subarray was found, return -1, otherwise return the minimum length
        return (ans == INT_MAX) ? -1 : ans;
    }
};