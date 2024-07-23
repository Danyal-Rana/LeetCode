#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums)
    {
        unordered_map<int, int> myMap;
        vector<int> ans;

        for (int num : nums)
        {
            myMap[num]++;
        }

        vector<pair<int, int>> freqPairs;
        for (auto& it : myMap)
        {
            freqPairs.push_back(it);
        }

        sort(freqPairs.begin(), freqPairs.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) 
                return a.first > b.first;
            return a.second < b.second;  
        });

        for (auto& it : freqPairs)
        {
            for (int i = 0; i < it.second; i++)
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};