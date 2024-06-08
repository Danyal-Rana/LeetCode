class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> myMap;
        myMap[0] = -1;
        int sum = 0;

        for (int i=0; i<n; i++)
        {
            sum += nums[i];

            if (myMap.find(sum%k) != myMap.end())
            {
                if (i - myMap[sum%k] > 1)
                {
                    return true;
                }
            }
            else
            {
                myMap[sum%k] = i;
            }
        }
        return false;        
    }
};