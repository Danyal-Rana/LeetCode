class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
    {
        unordered_map<int, int> m;
        
        for (auto i : arr)
        {
            m[i]++;
        }
        
        int n = arr.size();
        
        for (auto i : m)
        {
            if (i.second > n/4)
            {
                return i.first;
            }
        }
        
        return -1;
    }
};