class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        
        unordered_map<int, int> nums1Map;

        for (int num : nums1) {
            nums1Map[num]++;
        }

        for (int num : nums2) {
            if (nums1Map[num] > 0) {
                result.push_back(num);
                nums1Map[num]--;
            }
        }

        return result;
    }
};
