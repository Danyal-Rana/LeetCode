class Solution {
public:
    bool divideArray(vector<int>& nums)
    {
        unordered_map<int, int> myMap;
        if(nums.size()%2 != 0)
        {
            return false;
        }

        for(int i=0; i<nums.size(); i++)
        {
            myMap[nums[i]]++;
        }

        for(int i=0; i<myMap.size(); i++)
        {
            if (myMap[i]%2 != 0)
            {
                return false;
            }
        }

        return true;
    }
};