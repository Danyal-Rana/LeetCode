class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        unordered_map <int, int> myCounter;
        
        for (auto i :nums)
        {
            myCounter[i]++;
        }
        
        int maxFreq = 0;
        for (auto i : myCounter)
        {
            maxFreq = max (maxFreq, i.second);
        }
        
        int maxFreqElements = 0;
        for (auto i : myCounter)
        {
            if (i.second == maxFreq)
            {
                maxFreqElements++;
            }
        }
        
        return maxFreq * maxFreqElements;
    }
};