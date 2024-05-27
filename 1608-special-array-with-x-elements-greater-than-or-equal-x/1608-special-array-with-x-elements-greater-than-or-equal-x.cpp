class Solution {
public:
    int specialArray(vector<int>& nums)
    {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i=1; i<=n; i++)
        {
            int myCounter = 0;
            
            for (auto num : nums)
            {
                if (num >= i)
                {
                    myCounter++;
                }
            }
            if (myCounter == i)
            {
                return i;
            }
        }
        
        return -1;
    }
};