class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> myMap;
        
        vector<int> ans;
        
        int maxFrequency = 0;        
        for (auto i : nums)
        {
            myMap[i]++;
            maxFrequency = max(maxFrequency, myMap[i]);
        }
        
        vector<vector<int>> frequencyArray(maxFrequency + 1);
        
        for (auto i : myMap)
        {
            frequencyArray[i.second].push_back(i.first);
        }
        
        for (int i = maxFrequency; i >= 0 && k > 0; --i)
        {
            for (auto num : frequencyArray[i]) 
            {
                ans.push_back(num);
                k--;
                
                if (k == 0)
                {
                    break;
                }
            }
        }
        
        return ans;        
    }
};