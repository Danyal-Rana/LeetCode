class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> merged;  // {num, index_of_list}
        
        // Step 1: Merge all the lists
        for (int i = 0; i < nums.size(); ++i) {
            for (int num : nums[i]) {
                merged.push_back({num, i});
            }
        }
        
        // Step 2: Sort the merged list by the numbers
        sort(merged.begin(), merged.end());
        
        // Step 3: Sliding window
        unordered_map<int, int> count;  // Keeps track of the number of elements from each list in the window
        int left = 0, right = 0;
        int k = nums.size();  // Number of lists
        int numListsCovered = 0;  // Number of lists currently represented in the window
        int minRange = INT_MAX;
        pair<int, int> result;
        
        while (right < merged.size()) {
            // Expand the window by adding the element at `right`
            int listIdx = merged[right].second;
            count[listIdx]++;
            if (count[listIdx] == 1) numListsCovered++;  // New list covered
            right++;
            
            // When the window covers all the lists, try to shrink it
            while (numListsCovered == k) {
                int rangeStart = merged[left].first;
                int rangeEnd = merged[right - 1].first;
                
                if (rangeEnd - rangeStart < minRange) {
                    minRange = rangeEnd - rangeStart;
                    result = {rangeStart, rangeEnd};
                }
                
                // Shrink the window by moving `left`
                int leftListIdx = merged[left].second;
                count[leftListIdx]--;
                if (count[leftListIdx] == 0) numListsCovered--;  // No longer covering this list
                left++;
            }
        }
        
        return {result.first, result.second};
    }
};