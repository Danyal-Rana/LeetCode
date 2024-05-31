class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        unordered_map<int, int> frequencyMap;
        vector<int> ans;
        
        for (auto num : nums)
        {
            frequencyMap[num]++;
        }
        
        for (auto i : frequencyMap)
        {
            if (i.second == 1)
            {
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};