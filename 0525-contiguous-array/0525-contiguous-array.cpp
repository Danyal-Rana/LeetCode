class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        unordered_map<int, int> myMap;
        int sum = 0;
        int ans = 0;
        
        for (int i=0; i<nums.size(); i++)
        {
            sum += nums[i]==0?-1:1;
            
            if (sum == 0)
            {
                if (ans < i+1)
                {
                    ans = i+1;
                }
            }
            else if (myMap.find(sum) != myMap.end())
            {
                if (ans < i-myMap[sum])
                {
                    ans = i-myMap[sum];
                }
            }
            else
            {
                myMap[sum] = i;
            }
        }        
        
        return ans;
    }
};