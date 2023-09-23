class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int,int> myMap;
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];

            if (myMap.find(num) != myMap.end() && i - myMap[num] <= k)
            {
                return true;
            }
            else 
            {
                myMap[num] = i;
            }
        }
        return false;
    }
};