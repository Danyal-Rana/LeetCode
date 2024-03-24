class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
       set<int> mySet;
        
        for (int i=0; i<nums.size(); i++)
        {
            int x = nums[i];
            if (mySet.find(x) != mySet.end())
            {
                return x;
            }
            else
            {
                mySet.insert(x);
            }
        }
        return -1;
    }
};