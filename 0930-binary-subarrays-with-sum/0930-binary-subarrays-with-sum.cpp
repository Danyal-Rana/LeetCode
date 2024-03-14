class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        unordered_map <int, int> myMap;
        int sum = 0;
        int myCounter = 0;
        
        for (int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            
            if (sum == goal)
            {
                myCounter++;
            }
            
            if (myMap.find(sum-goal) != myMap.end())
            {
                myCounter += myMap[sum-goal];
            }
            
            if (myMap.find(sum) != myMap.end())
            {
                myMap[sum]++;
            }
            else
            {
                myMap[sum] = 1;
            }
        }
        return myCounter;
    }
};