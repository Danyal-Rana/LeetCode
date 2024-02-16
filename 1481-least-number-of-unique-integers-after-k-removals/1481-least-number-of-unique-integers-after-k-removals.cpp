class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> myMap;
        int myCounter = 0;
        
        for (auto i : arr)
        {
            myMap[i]++;
        }
        
        multimap<int, int> mm;        
        for (auto i : myMap)
        {
            mm.insert ({i.second, i.first});
        }
        
        for (auto i=mm.begin(); i!=mm.end(); i++)
        {
            k -= i->first;
            
            if (k < 0)
            {
                return mm.size()-myCounter;
            }
            myCounter++;
        }
        
        return 0;
    }
};