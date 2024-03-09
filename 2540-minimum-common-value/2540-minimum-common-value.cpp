class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map <int, int> myMap;
        
        for (auto i : nums1)
        {
            myMap[i]++;
        }
        for (auto i : nums2)
        {
            if (myMap[i] > 0)
                return i;
        }
        
        return -1;
    }
};